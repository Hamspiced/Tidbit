BOOTLOADER = Pro Micro

VIA_ENABLE = yes			# Use Via
OLED_DRIVER_ENABLE = yes	# OLED Screen
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
EXTRAKEY_ENABLE = yes       # Audio control and System control
ENCODER_ENABLE = yes        # Use rotary encoder
LTO_ENABLE = yes            # Link-time optimization
WPM_ENABLE = yes			# Bongo Cat WPM meter
NO_USB_STARTUP_CHECK = yes	# OSX Fix stated in Readme

SRC += keymaps/hamspiced/tidbit_encoder.c
SRC += keymaps/hamspiced/via_extras.c
SRC += i2c_master.c
SRC += bitc_led.c
SRC += tmk_core/common/uart.c
