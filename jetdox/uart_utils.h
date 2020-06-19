#ifndef UART_UTILS_H
#define UART_UTILS_H

#include "quantum.h"

void initialize_uart(void);
void uart_send_command_string(void);
uint8_t uart_read_data(void);


#endif
