#include "jetdox.h"
#include "uart_utils.h"


void matrix_init_kb(void) {
    matrix_init_user();
    initialize_uart();
}
