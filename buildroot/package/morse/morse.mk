################################################################################
#
# morse
#
################################################################################

MORSE_VERSION = 1.0
MORSE_SITE = $(TOPDIR)/../board/package/morse
MORSE_SITE_METHOD = local
MORSE_DEPENDENCIES = libgpiod
MORSE_LICENSE = Proprietary

$(eval $(cmake-package))