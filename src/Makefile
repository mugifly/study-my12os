PREFIX	=	/usr/local
ARCH	=	h8300-elf
BINDIR	=	$(PREFIX)/BINDIR
ADDNAME	=	$(ARCH)-

# Definition of tools
AR		=	$(BINDIR)/$(ADDNAME)AR
AS		=	$(BINDIR)/$(ADDNAME)as
CC		=	$(BINDIR)/$(ADDNAME)gcc
LD		=	$(BINDIR)/$(ADDNAME)ld
NM		=	$(BINDIR)/$(ADDNAME)nm
OBJCOPY	=	$(BINDIR)/$(ADDNAME)objcopy
OBJDUMP	=	$(BINDIR)/$(ADDNAME)objdump
RANLIB	=	$(BINDIR)/$(ADDNAME)ranlib
STRIP	=	$(BINDIR)/$(ADDNAME)strip
H8WRITE	=	../vendor/h8write/h8write

# Definition of serial-port name
# Linux: /dev/ttySx, Linux(USB):/dev/ttyUSBx, Windows: comX
H8WRITE_SERDEV = /dev/cuad0

# Definition of source files
OBJS = vector.o startup.o main.o
OBJS += lib.o serial.o

# Output (execute) file name
TARGET = kzload

# Compile options. ref: 34 page.
CFLAGS = -Wall -mh -nostdinc -nostdlib -fno-builtin
# CFLAGS += -mint32
# I : Find path of header file
CFLAGS += -I.
#CLAGS += -g
# Os : Size optimization
CFLAGS += -Os
CFLAGS += -DKZLOAD

# Link options
# static : All static link
# T : Specified link script
# L : Find path of library
LFLAGS = -static -T ld.scr -L.

.SUFFIXES: .c .o
.SUFFIXES: .s .o

all				:	$(TARGET)

# Generate rule of execute file
$(TARGET)		:	$(OBJS)
					$(CC) $(OBJS) -o $(TARGET) $(CFLAGS) $(LFLAGS)
					cp $(TARGET) $(TARGET).elf
					$(STRIP) $(TARGET)

# Compile rule of *.c file
.c.o 			:	$<
					$(CC) -c $(CFLAGS) $<

# Assemble rule of assembler file
.s.o				:	$<
					$(CC) -c $(CFLAGS) $<

# Rule of convert to Motorola S record format
$(TARGET).mot	:	$(TARGET)
					$(OBJCOPY) -O srec $(TARGET) $(TARGET).mot

image			:	$(TARGET).mot

# Transport to flash ROM
write			:	$(TARGET).mot
					$(H8WRITE) -3069 -f20 $(TARGET).mot $(H8WRITE_SERDEV)

# Clean up the directory
clean			:	rm -f $(OBJS) $(TARGET) $(TARGET).elf $(TARGET).mot
