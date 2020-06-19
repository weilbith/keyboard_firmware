#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#if defined(__AVR__)
#include <avr/io.h>
#endif
#include "wait.h"
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"
#include "timer.h"
#include "jetdox.h"
#include "uart_utils.h"


#define print_matrix_header()  print("\nr/c 0123456789ABCDEF\n")
#define print_matrix_row(row)  print_bin_reverse16(matrix_get_row(row))
#define matrix_bitpop(i)       bitpop16(matrix[i])
#define ROW_SHIFTER ((uint16_t)1)

#define UART_MATRIX_SIZE (MATRIX_COLS / 2)
#define uint8_get_bit_at_index(uint8, index) (!!((uint8 << index) & 128))


static matrix_row_t matrix[MATRIX_ROWS] = {0};
static uint8_t uart_matrix[UART_MATRIX_SIZE] = {0};


__attribute__ ((weak))
void matrix_init_kb(void) {
    matrix_init_user();
}

__attribute__ ((weak))
void matrix_init_user(void) {}

void print_bits_uint8_t(uint8_t data) {
  for (int i = 0; i < 8; i++) {
    uprintf("%d", !!((data << i) & 128));
  }

  uprintf("\n");
}

void print_uart_matrix(void) {
  uprintf("UART Matrix:\n");
  for (int i = 0; i < UART_MATRIX_SIZE; i++) {
    print_bits_uint8_t(uart_matrix[i]);
  }
  uprintf("\n");
}

void clear_uart_matrix(void) {
  for (int i = 0; i < UART_MATRIX_SIZE; i++) {
    uart_matrix[i] = 0;
  }
}

void update_uart_matrix(void) {
  clear_uart_matrix();
  uart_send_command_string();

  for (int i = 0; i < UART_MATRIX_SIZE; i++) {
    uart_matrix[i] = uart_read_data();
  }
}

void convert_and_store_uart_matrix_to_qmk_format(void) {
  for (int row = 0; row < MATRIX_ROWS; row++) {
    int index_one = row;
    int index_two = row + 4;
    matrix[row] = (uint8_get_bit_at_index(uart_matrix[0], index_one) << 9) | \
                  (uint8_get_bit_at_index(uart_matrix[0], index_two) << 8) | \
                  (uint8_get_bit_at_index(uart_matrix[1], index_one) << 7) | \
                  (uint8_get_bit_at_index(uart_matrix[1], index_two) << 6) | \
                  (uint8_get_bit_at_index(uart_matrix[2], index_one) << 5) | \
                  (uint8_get_bit_at_index(uart_matrix[2], index_two) << 4) | \
                  (uint8_get_bit_at_index(uart_matrix[3], index_one) << 3) | \
                  (uint8_get_bit_at_index(uart_matrix[3], index_two) << 2) | \
                  (uint8_get_bit_at_index(uart_matrix[4], index_one) << 1) | \
                  (uint8_get_bit_at_index(uart_matrix[4], index_two) << 0);
  }
}

void matrix_init(void) {
  matrix_init_quantum();
}

uint8_t matrix_scan(void) {
  uart_send_command_string();
  update_uart_matrix();
  /* print_uart_matrix(); */
  convert_and_store_uart_matrix_to_qmk_format();
  matrix_print();
  /* matrix_scan_quantum(); */
  return 1;
}


inline
matrix_row_t matrix_get_row(uint8_t row) {
  return matrix[row];
}


void matrix_print(void) {
  print_matrix_header();

  for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
      phex(row); print(": ");
      print_matrix_row(row);
      print("\n");
  }
}
