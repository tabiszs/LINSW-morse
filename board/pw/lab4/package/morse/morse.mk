################################################################################
#
# morse
#
################################################################################

MORSE_VERSION = 1.0
MORSE_SITE = $(TOPDIR)/../board/pw/lab4/morse
MORSE_SITE_METHOD = local
MORSE_DEPENDENCIES = libgpiod
MORSE_LICENSE = Proprietary

$(eval $(cmake-package))