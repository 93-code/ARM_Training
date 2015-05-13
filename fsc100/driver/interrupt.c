#include <s5pc100.h>

typedef void (*handler_t)(void);

void do_irq(void)
{
	handler_t handler;

	handler = (handler_t)VIC0ADDRESS;

	handler();

	VIC0ADDRESS = 0;

	return;
}

int enable_irq()
{
	int status;

	asm(
		"mrs r0,cpsr\n"
		"mov r1,#1\n"
		"bic r0,r0,r1,lsl #7\n"
		"msr cpsr,r0\n"
		"mov %0,r0\n"
		:"=r"(status)
		:
		:"r0","r1"
	);

	return status;
}
