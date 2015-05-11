
int enable_irq()
{
	int status;
	asm(
		"mrs r8,cpsr\n"
		"mov r7,#1\n"
		"bic r8,r8,r7,lsl #7\n"
		"msr cpsr,r8\n"
		"mov %0,r8\n"
		:"=r"(status)
		:
		:"r7","r8"
	);
	return status;
}

int disable_irq()
{
	int status;
	asm(
		"mrs r8,cpsr\n"
		"mov r7,#1\n"
		"orr r8,r7,lsl #7\n"
		"msr cpsr,r8\n"
		"mov %0,r8\n"
		:"=r"(status)
		:
		:"r7","r8"
	);
	return status;
}

int main()
{
	int status;

	enable_irq;


	disable_irq;

	return 0;
}
