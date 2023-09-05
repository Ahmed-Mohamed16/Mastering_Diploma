#@copyright : Ahmed Mohamed El-Sayed

Project_Name=learn_in_depth_cortex_m3

CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3
INCS=-I .
LIBS=

SRC=$(wildcard *.c)
ASS=$(wildcard *.s)

SRC_OBJ=$(SRC:.c=.o)
ASS_OBJ=$(ASS:.s=.o)

nothing:
	@echo "Work Please"

all: $(Project_Name).bin
	@echo ">>>>>>Build is done<<<<<<"

startup.o: startup.s
	$(CC)-as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)-gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(Project_Name).elf: $(SRC_OBJ) $(ASS_OBJ)
	$(CC)-ld.exe -T linker_script.ld $(LIBS) $(SRC_OBJ) $(ASS_OBJ) -o $@ -Map=Map_file.map

$(Project_Name).bin: $(Project_Name).elf
	$(CC)-objcopy.exe -O binary $< $@

clean_all:
	rm *.o *.elf *.bin

clean:
	rm *.elf *.bin
	
