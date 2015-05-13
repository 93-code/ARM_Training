#include <s5pc100.h>

#if 0
<1>设置GPIO为中断模式
<2>设置外中断源的触发方法
<3>设置Mask寄存器,取消屏蔽
<4>设置中断控制器
   [1]使能中断
   [2]选择IRQ
   [3]写中断处理函数的入口地址VICVECTADDR[0-31]
#endif

void key_handler(void)
{
	int i;
	int flag = 0;

	//清除PENDING
	//WKUP_INT0_7_PEND |= (1 << 1);
	WKUP_INT0_7_PEND  = WKUP_INT0_7_PEND;

	//打印key1
	puts("key1\r\n");

	//设为输入模式
	GPH0.GPH0CON &= ~(0xffff << 4);
	GPH0.GPH0CON &= ~(0xff   << 24);

	for(i = 1;i <= 7;i ++)
	{
		if(i == 5)
			continue;

		//探测到时低电平,继续探测，直到高电平
		flag = GPH0.GPH0DAT & (1 << i);
		if(flag == 0)
		{
			play_tone_on(i);

			do{
				flag = GPH0.GPH0DAT & (1 << i);
			}while(!flag);

			break;
		}
	}


	//关闭蜂鸣器
	play_tone_off();

	//设为中断模式
	GPH0.GPH0CON |=  (0x2222 << 4);
	GPH0.GPH0CON |=  (0x22   << 24);

	return;
}

void key_interrupt_init()
{
	int i;
	int *addr = (int *)0xE4000100;

	for(i = 1;i <= 7; i ++)
	{
		if(i == 5)
			continue;

		GPH0.GPH0CON &= ~(0xf  << (4 * i));
		GPH0.GPH0CON |=  (0x2  << (4 * i));

		WKUP_INT0_7_MASK &= ~(1 << i);
		WKUP_INT0_7_CON &= ~(0x7 << (4 * i));
		WKUP_INT0_7_CON |=  (0x2 << (4 * i));

		VIC0INTERRUPT.VIC0INTENABLE |= (1 << i);
		*(addr + i)  = (int)key_handler;
	}

	return;
}

void test_key_interrupt()
{
	//初始化
	key_interrupt_init();

	//执行流水灯
	water_led();

	return;
}
