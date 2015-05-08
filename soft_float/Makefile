CC=arm-none-eabi-gcc
AS=arm-none-eabi-as
LD=arm-none-eabi-ld
OBJDUMP=arm-none-eabi-objdump
RM=rm -rf
CFLAG= -g -c 
ASFLAG=-g -c
OBJ=start.o main.o
LDFLAGS= -static -L\
 "C:\Program Files\yagarto\lib\gcc\arm-none-eabi\4.6.2" -lgcc

#…Ë÷√±‡“Îƒ£ Ω
%.o:%.S
	$(CC) $(ASFLAG) $< -o $@	

%.o:%.c
	$(CC) $(CFLAG)  $< -o $@

all:$(OBJ)
	$(LD)  -Ttext=0x20000 $^ -o arm.elf $(LDFLAGS)
	$(OBJDUMP) -D arm.elf > arm.dis
	 
clean:
	$(RM) *.o arm.dis arm.elf