#include <s5pc100.h>

void uart0_init()
{
	//GPIO口初始化
	GPA0.GPA0CON &= ~(0xff << 0);
	GPA0.GPA0CON |= (0x22 << 0);

	//初始化UART控制器
	UART0.ULCON0 = 0x3;
	UART0.UCON0  = 0x5;

	//设置波特率
	UART0.UBRDIV0 = 34;
	UART0.UDIVSLOT0 = 0xDDDD;

	return;
}


//发送数据
void uart0_send(unsigned char data)
{
	int flag = 0;

	UART0.UTXH0 = data;

	//判断是否发送完
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

//接收数据
unsigned char uart0_recv()
{
	int flag = 0;
	//判断是否接收到数据
	 do{
	 	flag = UART0.UTRSTAT0 & (1 << 0);
	 }while(!flag);

	return UART0.URXH0;
}


void test_uart()
{
	char data;
	char *string = "hello word";

	//串口初始化
	uart0_init();

	//测试发送
	for(;*string != '\0'; string ++)
	{
		uart0_send(*string);
	}

	//测试接收
	while(1)
	{
		 data = uart0_recv();
		 uart0_send(data);
	}

	return ;
}
