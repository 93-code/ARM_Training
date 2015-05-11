#include <s5pc100.h>

<<<<<<< HEAD
void init_uart()
=======
void uart_init()
>>>>>>> e5522cd... Update arm
{
	//设置GPA0为UART
	GPA0.GPA0CON = (0x2 << 0) | (0x2 << 4);
	//设置UART相关控制器：
	UART0.ULCON0 = (0x3 << 0);
	UART0.UCON0 = (0x1 << 0) | (0x1 << 2);
	//设置波特率
	UART0.UBRDIV0 = 34;
	UART0.UDIVSLOT0 = 0xDDDD;
}

void uart_send(unsigned char data)
{
	int flag = 0;
	UART0.UTXH0 = data;

	do{
		flag = UART0.UTRSTAT0 & (1 << 2);
	}while (!flag);

	return;
}

<<<<<<< HEAD
char *puts(char *string)
{
	char *p = string;
	while (*p != '\0'){
		uart_send(*p);
		p++;
	}
	return string;
}


=======
>>>>>>> e5522cd... Update arm
unsigned char uart_recv()
{
	int flag = 0;
	do{
		flag = UART0.UTRSTAT0 & (1 << 0);
	}while (!flag);
	return UART0.URXH0;
}

void uart_test()
{
	unsigned char index;
	unsigned char data;
<<<<<<< HEAD
	char *string = "Hello";
	//init
	init_uart();
=======
	char *string = "Hello xxxxx";
	//init
	uart_init();
>>>>>>> e5522cd... Update arm
	//send
	while (*string != '\0'){
		uart_send(*string);
		string++;
	}
	//recv
	while (1){
		data = uart_recv();
		index = data - '0';
		play_tone(index, index/2);
		uart_send(data);
	}


	return;
}
