#if 0

1.�����жϿ����� [VIC2  23]
2.����ADCCON
3.ʹ��ADת��

void adc_handler(void)
{
	��ADCDAT0
	uart_printf("V:%dmv\r\n",3300 * (ADCDAT0/0xfff));

	//���ADCPEND
	//���VIC2ADDR,VIC1ADDR,VIC0ADDR

	delay(1);

	//ʹ��ADת��
	return;
}

#endif
