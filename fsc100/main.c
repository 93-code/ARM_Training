int main()
{
	int data = 100;
	system_clock_init();
	uart0_init();
	enable_irq();

	uart_printf("Hello word\r\n");
	uart_printf("data = %d\r\n",data);

	test_key_interrupt();
	return 0;
}
