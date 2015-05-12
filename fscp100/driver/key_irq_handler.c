#include <s5pc100.h>

void key_irq_handler(void)
{
	int flag = 0;
	//���pending
	WKUP_INT0_7_PEND |= (1 << 1);
	//��ӡkey1
	puts("key1");

	//��Ϊ����ģʽ
		GPH0.GPH0CON &= ~(0xf << 4);

		//̽�⵽ʱ�͵�ƽ[�򿪷�����],����̽�⣬ֱ���ߵ�ƽ
		do{
			flag = GPH0.GPH0DAT & (1 << 1);
			play_tone_on(1);

		}while(!flag);

		//�رշ�����
		play_tone_off();

		//��Ϊ�ж�ģʽ
		GPH0.GPH0CON |=  (0x2 << 4);
	return;
}

void init_key_irq(void)
{
	//�����ж�
	GPH0.GPH0CON &= ~(0xf << 4);
	GPH0.GPH0CON |= (2 << 4);
	//���ô�����ʽΪ����ģʽ
	WKUP_INT0_7_CON &= ~(0x7 << 4);
	WKUP_INT0_7_CON |= (0x2 << 4);
	//����Mask��������
	WKUP_INT0_7_MASK &= ~(0x1 << 1);

	//�����жϿ�����
	//ѡ���жϷ�ʽ
	VIC0INTERRUPT.VIC0INTSELECT &= ~(1 << 1);
	//�����ж�ʹ��
	VIC0INTERRUPT.VIC0INTENABLE |= (1 << 1);
	//�����жϴ�����(int1)
	VIC0VECTADDR.VIC0VECTADDR1 = (int)key_irq_handler;
	return;
}

void test_key_irq(void)
{
	init_key_irq();
	water_led();
	return;
}
