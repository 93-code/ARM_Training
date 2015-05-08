all:
	arm-none-eabi-gcc -c -g irq.c -o main.o
	arm-none-eabi-ld -Ttext=0x20000 main.o -o asm.elf
	arm-none-eabi-objdump -D asm.elf > asm.dis

clean:
	rm -rf asm.o asm.elf