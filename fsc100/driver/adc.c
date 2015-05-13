#if 0

1.设置中断控制器 [VIC2  23]
2.设置ADCCON
3.使能AD转换

void adc_handler(void)
{
	读ADCDAT0
	uart_printf("V:%dmv\r\n",3300 * (ADCDAT0/0xfff));

	//清除ADCPEND
	//清除VIC2ADDR,VIC1ADDR,VIC0ADDR

	delay(1);

	//使能AD转换
	return;
}

#endif
