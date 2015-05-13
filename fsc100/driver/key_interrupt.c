#include <s5pc100.h>

#if 0
<1>����GPIOΪ�ж�ģʽ
<2>�������ж�Դ�Ĵ�������
<3>����Mask�Ĵ���,ȡ������
<4>�����жϿ�����
   [1]ʹ���ж�
   [2]ѡ��IRQ
   [3]д�жϴ���������ڵ�ַVICVECTADDR[0-31]
#endif

void key_handler(void)
{
	int i;
	int flag = 0;

	//���PENDING
	//WKUP_INT0_7_PEND |= (1 << 1);
	WKUP_INT0_7_PEND  = WKUP_INT0_7_PEND;

	//��ӡkey1
	puts("key1\r\n");

	//��Ϊ����ģʽ
	GPH0.GPH0CON &= ~(0xffff << 4);
	GPH0.GPH0CON &= ~(0xff   << 24);

	for(i = 1;i <= 7;i ++)
	{
		if(i == 5)
			continue;

		//̽�⵽ʱ�͵�ƽ,����̽�⣬ֱ���ߵ�ƽ
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


	//�رշ�����
	play_tone_off();

	//��Ϊ�ж�ģʽ
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
	//��ʼ��
	key_interrupt_init();

	//ִ����ˮ��
	water_led();

	return;
}
