
int main()
{
	system_clock_init();
<<<<<<< HEAD
	init_uart();
	enable_irq();
	//test_key_irq();
	//water_led();
=======
	//��ʼ��LED
	water_led();
	//scan_key();
>>>>>>> c1be9bf... Add clock

	while (1)
	uart_printf("Hello\n");
	return 0;
}

