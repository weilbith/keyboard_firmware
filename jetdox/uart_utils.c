#include "uart_utils.h"

// #define SERIAL_UART_TXD_READY (UCSR1A & _BV(UDRE1))
void uart_set_double_speed_flag(void) {
    UCSR1A = _BV(U2X1);
}

void uart_set_bau_rate(unsigned long bau_rate) {
    unsigned long register_value = (F_CPU / (8UL * bau_rate) - 1);
    UBRR1L = register_value;
    UBRR1H = register_value >> 8;
}

void uart_enable_read_write(void) {
    UCSR1B = _BV(TXEN1) | _BV(RXEN1);
}

void uart_set_8bit_word_length_and_stop_bit(void) {
    UCSR1C = _BV(UCSZ11) | _BV(UCSZ10);
}

void initialize_uart(void) {
    uart_set_double_speed_flag();
    uart_set_bau_rate((long) 115200);
    uart_enable_read_write();
    uart_set_8bit_word_length_and_stop_bit();
}

void uart_send_command_string(void) {
    SERIAL_UART_DATA = 's' ;
}

bool is_uart_receiving_done(void) {
    return UCSR1A & _BV(RXC1);
}

uint8_t uart_read_data(void) {
    uint32_t timeout = 0;

    while(!is_uart_receiving_done()){
        if (timeout > 1000000){
            return 0;
        } else {
            timeout++;
        }
    }

    return SERIAL_UART_DATA;
}
