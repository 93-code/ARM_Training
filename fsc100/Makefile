APPNAME=fsc100.elf
LIBNAME=fsc100
CFLAGS=-c -g
LDFLAGS=-L ./lib -l$(LIBNAME)

CROSS_COMPILE=arm-none-eabi-
CC=$(CROSS_COMPILE)gcc
AR=$(CROSS_COMPILE)ar
LD=$(CROSS_COMPILE)ld

#export 导出变量给子Makefile使用
export  CC LD AR CFLAGS LIBNAME

all:start.o  main.o  lib$(LIBNAME).a
	$(LD) -Ttext=0x20000 start.o main.o -o $(APPNAME) $(LDFLAGS)
	
start.o:./start/start.s
	$(CC) $(CFLAGS) $< -o $@
	
main.o:main.c
	$(CC) $(CFLAGS) $< -o $@
	
lib$(LIBNAME).a:
	make -C ./driver
	
clean:
	rm -rf *.o
	make -C ./lib clean
	