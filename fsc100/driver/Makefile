LIBPATH=../lib
HEADPATH=-I ../include
OBJS += $(LIBPATH)/key.o
OBJS += $(LIBPATH)/led.o 
OBJS += $(LIBPATH)/delay.o
OBJS += $(LIBPATH)/beep.o
OBJS += $(LIBPATH)/clock.o
OBJS += $(LIBPATH)/music.o
OBJS += $(LIBPATH)/wdt.o
OBJS += $(LIBPATH)/uart.o
OBJS += $(LIBPATH)/interrupt.o
OBJS += $(LIBPATH)/key_interrupt.o

all:$(OBJS)
	make -C ./printf
	#-C 切换到指定的路径下，调用其Makefile,默认寻找目标为all
	make -C $(LIBPATH)
	
$(LIBPATH)/%.o:%.c
	$(CC) $(CFLAGS) $< -o $@ $(HEADPATH)	 