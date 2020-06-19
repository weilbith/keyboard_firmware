MCU = at90usb1286
BOOTLOADER = halfkay

# Build Options
CUSTOM_MATRIX = yes
NKRO_ENABLE   = yes

# Debugging
CONSOLE_ENABLE = yes
COMMAND_ENABLE = yes

SRC += matrix.c \
			 uart_utils.c
