#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define ROWS 4
#define COLS 10

#define UART_MATRIX_SIZE (COLS / 2)
#define HALF_MATRIX_SIZE (UART_MATRIX_SIZE / 2 + 1)


void print_bits_uint8_t(uint8_t data) {
  for (int i = 0; i < 8; i++) {
    printf("%d", !!((data << i) & 128));
  }

  printf("\n");
}

void print_bits_uint16_t(uint16_t data) {
  printf("XXXXXX");

  for (int i = 6; i < 16; i++) {
    printf("%d", !!((data << i) & 32768));
  }

  printf("\n");
}

void print_both_half_matrix(
    char left_half_matrix[HALF_MATRIX_SIZE],
    char right_half_matrix[HALF_MATRIX_SIZE]
) {
  printf("Left Matrix:\n");
  for (int i = 0; i < HALF_MATRIX_SIZE -1; i++) {
    print_bits_uint8_t(left_half_matrix[i]);
  }
  for (int i = 0; i < 4; i++) {
    printf("%d", !!((left_half_matrix[2] << i) & 128));
  }
  printf("XXXX\n");
  printf("\n");

  printf("Right Matrix:\n");
  printf("XXXX");
  for (int i = 4; i < 8; i++) {
    printf("%d", !!((right_half_matrix[0] << i) & 128));
  }
  printf("\n");
  for (int i = 1; i < HALF_MATRIX_SIZE; i++) {
    print_bits_uint8_t(right_half_matrix[i]);
  }

  printf("\n");
}

void print_uart_matrix(char uart_matrix[UART_MATRIX_SIZE]) {
  printf("UART Matrix:\n");
  for (int i = 0; i < UART_MATRIX_SIZE; i++) {
    print_bits_uint8_t(uart_matrix[i]);
  }
  printf("\n");
}

void print_qmk_matrix(uint16_t qmk_matrix[ROWS]) {
  printf("QMK Matrix:\n");
  for (int i = 0; i < ROWS; i++) {
    print_bits_uint16_t(qmk_matrix[i]);
  }
  printf("\n");
}

/**
 * Original Matrix
 * ~> no data type
 * 00 01 02 03 04 05 06 07 08 09
 * 10 11 12 13 14 15 16 17 18 19
 * 20 21 22 23 24 25 26 27 28 29
 * 30 31 32 33 34 35 36 37 38 39
 */

/**
 * Transfer via UART with 8bit words
 * ~> uint8_t data[COLS/2]
 * => rotate columns to rows and concatenate two columns into one row
 *  7  6  5  4    3  2  1  0
 *  0  1  2  3    4  5  6  7
 * 00 10 20 30 | 01 11 21 31 |
 * 02 12 22 32 | 03 13 23 33 |
 * 04 14 24 34 | 05 15 25 35 |
 * 06 16 26 36 | 07 17 27 37 |
 * 08 18 28 38 | 09 19 29 39 |
 */

/**
 * ke-assemble received UART data to 16 bit rows
 * ~> uint16_t data[COLS]
 * => ?
 * XX XX XX XX XX XX 00 01 02 03 04 05 06 07 08 09 |
 * XX XX XX XX XX XX 10 11 12 13 14 15 16 17 18 19 |
 * XX XX XX XX XX XX 20 21 22 23 24 25 26 27 28 29 |
 * XX XX XX XX XX XX 30 31 32 33 34 35 36 37 38 39 |
 */

typedef enum {
  LEFT_SITE = 0,
  RIGHT_SITE,
} split_half_site_t;

typedef enum {
  GPIO_NUM_00 = 0, GPIO_NUM_01, GPIO_NUM_02, GPIO_NUM_03, GPIO_NUM_04,
  GPIO_NUM_05, GPIO_NUM_06, GPIO_NUM_07, GPIO_NUM_08, GPIO_NUM_09,
  GPIO_NUM_10, GPIO_NUM_11, GPIO_NUM_12, GPIO_NUM_13, GPIO_NUM_14,
  GPIO_NUM_15, GPIO_NUM_16, GPIO_NUM_17, GPIO_NUM_18, GPIO_NUM_19,
  GPIO_NUM_20, GPIO_NUM_21, GPIO_NUM_22, GPIO_NUM_23, GPIO_NUM_24,
  GPIO_NUM_25, GPIO_NUM_26, GPIO_NUM_27, GPIO_NUM_28, GPIO_NUM_29,
  GPIO_NUM_30, GPIO_NUM_31, GPIO_NUM_32, GPIO_NUM_33, GPIO_NUM_34,
  GPIO_NUM_35, GPIO_NUM_36, GPIO_NUM_37, GPIO_NUM_38, GPIO_NUM_39,
} gpio_num_t; 

int gpio_get_level(gpio_num_t gpio_num) {
  switch(gpio_num) {
    case GPIO_NUM_00:
    case GPIO_NUM_04:
    case GPIO_NUM_14:
    case GPIO_NUM_24:
    case GPIO_NUM_34:
    case GPIO_NUM_05:
    case GPIO_NUM_15:
    case GPIO_NUM_25:
    case GPIO_NUM_35:
    case GPIO_NUM_39:
      return 1;

    default:
      return 0;
  }
}

/**
 * 00 10 20 30 | 01 11 21 31 |
 * 02 12 22 32 | 03 13 23 33 |
 * 04 14 24 34 | XX XX XX XX |
 */
void read_half_matrix_left(char half_matrix[HALF_MATRIX_SIZE]) {
  half_matrix[0] = ((gpio_get_level(GPIO_NUM_31) ? 1:0) << 0) | \
                   ((gpio_get_level(GPIO_NUM_21) ? 1:0) << 1) | \
                   ((gpio_get_level(GPIO_NUM_11) ? 1:0) << 2) | \
                   ((gpio_get_level(GPIO_NUM_01) ? 1:0) << 3) | \
                   ((gpio_get_level(GPIO_NUM_30) ? 1:0) << 4) | \
                   ((gpio_get_level(GPIO_NUM_20) ? 1:0) << 5) | \
                   ((gpio_get_level(GPIO_NUM_10) ? 1:0) << 6) | \
                   ((gpio_get_level(GPIO_NUM_00) ? 1:0) << 7);

  half_matrix[1] = ((gpio_get_level(GPIO_NUM_33) ? 1:0) << 0) | \
                   ((gpio_get_level(GPIO_NUM_23) ? 1:0) << 1) | \
                   ((gpio_get_level(GPIO_NUM_13) ? 1:0) << 2) | \
                   ((gpio_get_level(GPIO_NUM_03) ? 1:0) << 3) | \
                   ((gpio_get_level(GPIO_NUM_32) ? 1:0) << 4) | \
                   ((gpio_get_level(GPIO_NUM_22) ? 1:0) << 5) | \
                   ((gpio_get_level(GPIO_NUM_12) ? 1:0) << 6) | \
                   ((gpio_get_level(GPIO_NUM_02) ? 1:0) << 7);

  half_matrix[2] = ((gpio_get_level(GPIO_NUM_34) ? 1:0) << 4) | \
                   ((gpio_get_level(GPIO_NUM_24) ? 1:0) << 5) | \
                   ((gpio_get_level(GPIO_NUM_14) ? 1:0) << 6) | \
                   ((gpio_get_level(GPIO_NUM_04) ? 1:0) << 7);
}

/**
 * XX XX XX XX | 05 15 25 35 |
 * 06 16 26 36 | 07 17 27 37 |
 * 08 18 28 38 | 09 19 29 39 |
 */
void read_half_matrix_right(char half_matrix[HALF_MATRIX_SIZE]) {
  half_matrix[0] = ((gpio_get_level(GPIO_NUM_35) ? 1:0) << 0) | \
                   ((gpio_get_level(GPIO_NUM_25) ? 1:0) << 1) | \
                   ((gpio_get_level(GPIO_NUM_15) ? 1:0) << 2) | \
                   ((gpio_get_level(GPIO_NUM_05) ? 1:0) << 3);

  half_matrix[1] = ((gpio_get_level(GPIO_NUM_37) ? 1:0) << 0) | \
                   ((gpio_get_level(GPIO_NUM_27) ? 1:0) << 1) | \
                   ((gpio_get_level(GPIO_NUM_17) ? 1:0) << 2) | \
                   ((gpio_get_level(GPIO_NUM_07) ? 1:0) << 3) | \
                   ((gpio_get_level(GPIO_NUM_36) ? 1:0) << 4) | \
                   ((gpio_get_level(GPIO_NUM_26) ? 1:0) << 5) | \
                   ((gpio_get_level(GPIO_NUM_16) ? 1:0) << 6) | \
                   ((gpio_get_level(GPIO_NUM_06) ? 1:0) << 7);

  half_matrix[2] = ((gpio_get_level(GPIO_NUM_39) ? 1:0) << 0) | \
                   ((gpio_get_level(GPIO_NUM_29) ? 1:0) << 1) | \
                   ((gpio_get_level(GPIO_NUM_19) ? 1:0) << 2) | \
                   ((gpio_get_level(GPIO_NUM_09) ? 1:0) << 3) | \
                   ((gpio_get_level(GPIO_NUM_38) ? 1:0) << 4) | \
                   ((gpio_get_level(GPIO_NUM_28) ? 1:0) << 5) | \
                   ((gpio_get_level(GPIO_NUM_18) ? 1:0) << 6) | \
                   ((gpio_get_level(GPIO_NUM_08) ? 1:0) << 7);
}


void receive_half_matrix(
  split_half_site_t site,
  char half_matrix[HALF_MATRIX_SIZE],
  char uart_matrix[UART_MATRIX_SIZE]
) {
  switch(site) {
    case LEFT_SITE:
      uart_matrix[0] = half_matrix[0];
      uart_matrix[1] = half_matrix[1];
      uart_matrix[2] = half_matrix[2] | uart_matrix[2];
      break;

    case RIGHT_SITE:
      uart_matrix[2] = uart_matrix[2] | half_matrix[0];
      uart_matrix[3] = half_matrix[1];
      uart_matrix[4] = half_matrix[2];
  }
}

#define uint8_bit_at_index(uint8, index) (!!((uint8 << index) & 128))

void convert_uart_to_qmk_matrix(char uart_matrix[], uint16_t qmk_matrix[]) {
  /**
    * row 0 (00 01 02 03 04 05 06 07 08 09)
    * 0 - 0,4 ~> 00 01
    * 1 - 0,4 ~> 02 03
    * 2 - 0,4 ~> 04 05
    * 3 - 0,4 ~> 06 07
    * 4 - 0,4 ~> 08 09
    *
    * row 1 (10 11 12 13 14 15 16 17 18 19)
    * 0 - 1,5 ~> 10 11
    * 1 - 1,5 ~> 12 13
    * 2 - 1,5 ~> 14 15
    * 3 - 1,5 ~> 16 17
    * 4 - 0,4 ~> 18 19
    *
    * row 2 ...
    */
  for (int row = 0; row < ROWS; row++) {
    int index_one = row;
    int index_two = row +4;
    qmk_matrix[row] = (uint8_bit_at_index(uart_matrix[0], index_one) << 9) | \
                      (uint8_bit_at_index(uart_matrix[0], index_two) << 8) | \
                      (uint8_bit_at_index(uart_matrix[1], index_one) << 7) | \
                      (uint8_bit_at_index(uart_matrix[1], index_two) << 6) | \
                      (uint8_bit_at_index(uart_matrix[2], index_one) << 5) | \
                      (uint8_bit_at_index(uart_matrix[2], index_two) << 4) | \
                      (uint8_bit_at_index(uart_matrix[3], index_one) << 3) | \
                      (uint8_bit_at_index(uart_matrix[3], index_two) << 2) | \
                      (uint8_bit_at_index(uart_matrix[4], index_one) << 1) | \
                      (uint8_bit_at_index(uart_matrix[4], index_two) << 0);
  }
}


int main() {
  char left_half_matrix[HALF_MATRIX_SIZE] = {0};
  char right_half_matrix[HALF_MATRIX_SIZE] = {0};
  char uart_matrix[UART_MATRIX_SIZE] = {0};
  uint16_t qmk_matrix[ROWS] = {0};

  read_half_matrix_left(left_half_matrix);
  read_half_matrix_right(right_half_matrix);
  print_both_half_matrix(left_half_matrix, right_half_matrix);

  receive_half_matrix(LEFT_SITE, left_half_matrix, uart_matrix);
  receive_half_matrix(RIGHT_SITE, right_half_matrix, uart_matrix);

  print_uart_matrix(uart_matrix);

  convert_uart_to_qmk_matrix(uart_matrix, qmk_matrix);
  print_qmk_matrix(qmk_matrix);

  return 0;
}
