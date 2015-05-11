#include <s5pc100.h>

void key_irq_handler(void)
{
	int flag = 0;
	//清楚pending
	WKUP_INT0_7_PEND |= (1 << 1);
	//打印key1
	puts("key1");

	//设为输入模式
		GPH0.GPH0CON &= ~(0xf << 4);

		//探测到时低电平[打开蜂鸣器],继续探测，直到高电平
		do{
			flag = GPH0.GPH0DAT & (1 << 1);
			play_tone_on(1);

		}while(!flag);

		//关闭蜂鸣器
		play_tone_off();

		//设为中断模式
		GPH0.GPH0CON |=  (0x2 << 4);
	return;
}

void init_key_irq(void)
{
	//设置中断
	GPH0.GPH0CON &= ~(0xf << 4);
	GPH0.GPH0CON |= (2 << 4);
	//设置触发方式为触发模式
	WKUP_INT0_7_CON &= ~(0x7 << 4);
	WKUP_INT0_7_CON |= (0x2 << 4);
	//设置Mask，非屏蔽
	WKUP_INT0_7_MASK &= ~(0x1 << 1);

	//设置中断控制器
	//选择中断方式
	VIC0INTERRUPT.VIC0INTSELECT &= ~(1 << 1);
	//设置中断使能
	VIC0INTERRUPT.VIC0INTENABLE |= (1 << 1);
	//设置中断处理函数(int1)
	VIC0VECTADDR.VIC0VECTADDR1 = (int)key_irq_handler;
	return;
}

void test_key_irq(void)
{
	init_key_irq();
	water_led();
	return;
}
