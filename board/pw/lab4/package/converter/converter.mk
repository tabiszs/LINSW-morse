################################################################################
#
# morse-converter
#
################################################################################

MORSE_CONVERTER_VERSION = 1.0
MORSE_CONVERTER_SITE = $(TOPDIR)/../board/pw/lab4/converter
MORSE_CONVERTER_SITE_METHOD = local

define MORSE_CONVERTER_BUILD_CMDS
   $(MAKE) $(TARGET_CONFIGURE_OPTS) converter -C $(@D)
endef
define MORSE_CONVERTER_INSTALL_TARGET_CMDS 
   $(INSTALL) -D -m 0755 $(@D)/converter $(TARGET_DIR)/usr/bin 
endef
MORSE_CONVERTER_LICENSE = Proprietary

$(eval $(generic-package))
