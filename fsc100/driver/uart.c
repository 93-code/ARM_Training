#include <s5pc100.h>

void uart0_init()
{
	//GPIO�ڳ�ʼ��
	GPA0.GPA0CON &= ~(0xff << 0);
	GPA0.GPA0CON |= (0x22 << 0);

	//��ʼ��UART������
	UART0.ULCON0 = 0x3;
	UART0.UCON0  = 0x5;

	//���ò�����
	UART0.UBRDIV0 = 34;
	UART0.UDIVSLOT0 = 0xDDDD;

	return;
}


//��������
void uart0_send(unsigned char data)
{
	int flag = 0;

	UART0.UTXH0 = data;

	//�ж��Ƿ�����
	 do{
	 	flag = UART0.UTRSTAT0 & (1 << 2);
	 }while(!flag);

	 return;
}

char *puts(char *string)
{
	char *p;

	for(p = string; *p != '\0';p ++)
	{
		 uart0_send(*p);
	}

	return string;
}

//��������
unsigned char uart0_recv()
{
	int flag = 0;
	//�ж��Ƿ���յ�����
	 do{
	 	flag = UART0.UTRSTAT0 & (1 << 0);
	 }while(!flag);

	return UART0.URXH0;
}


void test_uart()
{
	char data;
	char *string = "hello word";

	//���ڳ�ʼ��
	uart0_init();

	//���Է���
	for(;*string != '\0'; string ++)
	{
		uart0_send(*string);
	}

	//���Խ���
	while(1)
	{
		 data = uart0_recv();
		 uart0_send(data);
	}

	return ;
}
