# Having a file like this allows you to override Makefile definitions
# for your own particular keymap

COMMAND_ENABLE   = no  # Commands for debug and configuration
SLEEP_LED_ENABLE = no  # Breathing sleep LED during USB suspend
NKRO_ENABLE      = yes # Nkey Rollover

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
