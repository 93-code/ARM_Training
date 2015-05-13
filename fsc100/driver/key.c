#include "s5pc100.h"

void key_init()
{
	GPH0.GPH0CON &=  ~(0xffff << 4);
	return;
}

void scan_key()
{
	int flag;
	int i;

	led_init(4);
	key_init();

	while(1)
	{

		for(i = 1;i <= 4;i ++)
		{
			flag = GPH0.GPH0DAT & (1 << i);

			if(flag == 0){
				led_on(i);
			}else{
				led_off(i);
			}
		}
	}

	return;
}
