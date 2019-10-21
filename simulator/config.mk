# project name
THIS = tt

# Path to top level ASF directory relative to this project directory.
PRJ_PATH = ../multipass/monome_euro/libavr32/asf

# Target CPU architecture: ap, ucr1, ucr2 or ucr3
ARCH = ucr2

# Target part: none, ap7xxx or uc3xxxxx
# PART = uc3b064
PART = uc3b0512

# Application target name. Given with suffix .a for library and .elf for a
# standalone application.
TARGET = $(THIS).a

# List of C source files.
CSRCS = \
       ../src/adc.c               \
       ../src/dac.c               \
       ../src/events.c            \
       ../src/fix.c               \
       ../src/font.c              \
       ../src/i2c.c               \
       ../src/init_common.c       \
       ../src/interrupts.c        \
       ../src/kbd.c               \
       ../src/midi_common.c       \
       ../src/monome.c            \
       ../src/music.c             \
       ../src/notes.c             \
       ../src/random.c            \
       ../src/region.c            \
       ../src/screen.c            \
       ../src/timers.c            \
       ../src/usb.c               \
       ../src/util.c              \
       ../src/usb/ftdi/ftdi.c     \
       ../src/usb/ftdi/uhi_ftdi.c \
       ../src/usb/hid/hid.c       \
       ../src/usb/hid/uhi_hid.c   \
       ../src/usb/midi/uhi_midi.c \
       ../src/usb/midi/midi.c     \
       ../src/usb/msc/msc.c       \
       avr32/drivers/adc/adc.c                            \
       avr32/drivers/flashc/flashc.c                      \
       avr32/drivers/gpio/gpio.c                          \
       avr32/drivers/intc/intc.c                          \
       avr32/drivers/pm/pm.c                              \
       avr32/drivers/pm/pm_conf_clocks.c                  \
       avr32/drivers/pm/power_clocks_lib.c                \
       avr32/drivers/spi/spi.c                            \
       avr32/drivers/tc/tc.c                              \
       avr32/drivers/twi/twi.c                            \
       avr32/drivers/usart/usart.c                        \
       avr32/drivers/usbb/usbb_host.c                     \
       avr32/services/fs/fat/fat.c                        \
       avr32/services/fs/fat/fat_unusual.c                \
       avr32/services/fs/fat/file.c                       \
       avr32/services/fs/fat/navigation.c                 \
       avr32/utils/debug/print_funcs.c                    \
       common/services/storage/ctrl_access/ctrl_access.c  \
       common/services/usb/class/msc/host/uhi_msc.c       \
       common/services/usb/class/msc/host/uhi_msc_mem.c   \
       common/services/spi/uc3_spi/spi_master.c           \
       common/services/usb/uhc/uhc.c                      \
       common/services/clock/uc3b0_b1/sysclk.c  

# List of assembler source files.
ASSRCS = \
       avr32/utils/startup/trampoline_uc3.S               \
       avr32/drivers/intc/exception.S                     \

# List of include paths.
INC_PATH = \
       ../../teletype                                      \
       ../../..                                           \
       ../../../../src                                    \
       ../src                                             \
       ../src/usb                                         \
       ../src/usb/cdc                                     \
       ../src/usb/ftdi                                    \
       ../src/usb/hid                                     \
       ../src/usb/midi                                    \
       ../src/usb/msc                                     \
       ../conf                                            \
       ../conf/teletype                                   \
       avr32/boards                                       \
       avr32/drivers/cpu/cycle_counter                    \
       avr32/drivers/flashc                               \
       avr32/drivers/gpio                                 \
       avr32/drivers/intc                                 \
       avr32/drivers/pm                                   \
       avr32/drivers/spi                                  \
       avr32/drivers/tc                                   \
       avr32/drivers/twi                                  \
       avr32/drivers/usart                                \
       avr32/drivers/usbb                                 \
       avr32/utils                                        \
       avr32/utils/debug                                  \
       avr32/utils/preprocessor                           \
       avr32/services/fs/fat                              \
       common/boards                                      \
       common/boards/user_board                           \
	   common/services/delay                              \
       common/services/storage/ctrl_access                \
       common/services/clock                              \
       common/services/usb/                               \
       common/services/usb/uhc                            \
       common/services/usb/class/msc                      \
       common/services/usb/class/msc/host                 \
       common/services/usb/class/hid                      \
       common/services/spi/uc3_spi                        \
       common/utils                              

LINKER_SCRIPT = ../src/link_uc3b0512.lds

# The most relevant symbols to define for the preprocessor are:
#   BOARD      Target board in use, see boards/board.h for a list.
#   EXT_BOARD  Optional extension board in use, see boards/board.h for a list.
CPPFLAGS = \
      -D BOARD=USER_BOARD -D UHD_ENABLE      