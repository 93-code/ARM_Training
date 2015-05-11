
#include "s5pc100.h"
void init_key()
{
	GPH0.GPH0CON &=  ~(0xffff << 4);

}

void scan_key()
{
	int flag;
	int i;

	init_led(4);
	init_key();

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
