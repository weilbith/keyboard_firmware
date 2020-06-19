#ifndef JETDOX_CONFIG_H
#define JETDOX_CONFIG_H

#include "config_common.h"

// USB device descriptor
#define VENDOR_ID       0x16C0
#define PRODUCT_ID      0x0478
#define DEVICE_VER      0x0001
#define MANUFACTURER    Thore Strassburg
#define PRODUCT         Jetdox
#define DESCRIPTION     QMK keyboard firmware for Jetdox

// Matrix
#define MATRIX_ROWS 4
#define MATRIX_COLS 10
#define DEBOUNCE 0  // handled by split sender chip already

// Serial communication
#define SERIAL_UART_DATA UDR1
#define SERIAL_UART_TXD_READY (UCSR1A & _BV(UDRE1))
#define SERIAL_UART_RXD_PRESENT (UCSR1A & _BV(RXC1))
#define SERIAL_UART_RXD_VECT USART1_RX_vect

#endif
