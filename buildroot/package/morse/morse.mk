################################################################################
#
# morse
#
################################################################################

MORSE_VERSION = 2.0
MORSE_SITE = $(TOPDIR)/../board/pw/lab4/morse
MORSE_SITE_METHOD = local
MORSE_DEPENDENCIES = libgpiod

define MORSE_BUILD_CMDS
   $(MAKE) $(TARGET_CONFIGURE_OPTS) morse -C $(@D)
endef
define MORSE_INSTALL_TARGET_CMDS 
   $(INSTALL) -D -m 0755 $(@D)/morse $(TARGET_DIR)/usr/bin 
endef
MORSE_LICENSE = Proprietary

$(eval $(generic-package))
