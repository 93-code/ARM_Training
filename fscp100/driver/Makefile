LIBPATH=../lib
HEADPATH=-I ../include

OBJS += $(LIBPATH)/key.o
OBJS += $(LIBPATH)/led.o
OBJS += $(LIBPATH)/delay.o
OBJS += $(LIBPATH)/beep.o
OBJS += $(LIBPATH)/clock.o
<<<<<<< HEAD
OBJS += $(LIBPATH)/wdt.o
OBJS += $(LIBPATH)/uart.o
OBJS += $(LIBPATH)/music.o
OBJS += $(LIBPATH)/interrupt.o
OBJS += $(LIBPATH)/key_irq_handler.o
=======
>>>>>>> c1be9bf... Add clock

all:$(OBJS)
	make -C ./printf
	make -C $(LIBPATH)

$(LIBPATH)/%.o:%.c
	$(CC) $(CFLAGS) $< -o $@ $(HEADPATH)