
int main()
{
	system_clock_init();
<<<<<<< HEAD
	init_uart();
	enable_irq();
	//test_key_irq();
	//water_led();
=======
	//³õÊ¼»¯LED
	 //test_wdt();
	//uart_test();
	//water_led();
	//scan_key();
<<<<<<< HEAD
>>>>>>> c1be9bf... Add clock
=======
	play_music();
>>>>>>> e5522cd... Update arm

	while (1)
	uart_printf("Hello\n");
	return 0;
}

