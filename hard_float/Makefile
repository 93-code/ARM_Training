CC=arm-none-eabi-gcc
AS=arm-none-eabi-as
LD=arm-none-eabi-ld
OBJDUMP=arm-none-eabi-objdump
RM=rm -rf
CFLAG=-g -c -mfpu=neon -mfloat-abi=softfp
ASFLAG=-g -c -mfpu=neon -mfloat-abi=softfp
OBJ=start.o main.o

#…Ë÷√±‡“Îƒ£ Ω
%.o:%.S
	$(CC) $(ASFLAG) $< -o $@	

%.o:%.c
	$(CC) $(CFLAG)  $< -o $@

all:$(OBJ) 
	$(LD)  -Ttext=0x20000 $^ -o arm.elf 
	$(OBJDUMP) -D arm.elf > arm.dis
	 
clean:
	$(RM) *.o arm.dis arm.elf