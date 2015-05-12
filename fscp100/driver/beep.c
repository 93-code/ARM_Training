#include <s5pc100.h>

void init_beep()
{
	//0xE0300080 [7:4] 0010
	//��ʼ��GPIOΪTOUT_1ģʽ 
	GPD.GPDCON &= ~(0xf << 4);
	GPD.GPDCON |=  (0x2 << 4);

	return;
}

void init_timer1(int tcnt_value,int tcmp_value)
{

	/*Timer Input Clock Frequency = PCLK / ( {prescaler value + 1} ) / {divider value}
	 *
	 * prescaler value = 199
	 * divider value   = 16
	 *
	 *
	 * Timer1 In Clock = 66MHZ/(199 + 1)/16
	 *                 = 20625HZ
	 *
	 * 0XEA000000
	 */
	TIMER.TCFG0 &= ~0xff; //8λ��0
	TIMER.TCFG0 |= (199 << 0); //Prescaler0 [7:0] 199
	TIMER.TCFG1 &= ~(0xf << 4); //
	TIMER.TCFG1 |= (0x1 << 4);

	//���������ͱȽ�����ֵ
	TIMER1.TCNTB1 = tcnt_value;
	TIMER1.TCMPB1 = tcmp_value;

	//���ֶ�����λ
	TIMER.TCON |= (1 << 9);

	//����ֶ�����λ
	TIMER.TCON &= ~(1 << 9);

	return;
}

void start_timer1()
{
	TIMER.TCON |= (1 << 8) | (1 << 11);
	return;
}

void stop_timer1()
{
	TIMER.TCON &= ~(1 << 8);
	return;
}

void mdelay(int time)
{
	int i;
	for(i = 0; i < time*5000; i++);
	return;
}

void test_beep()
{
	 init_beep();
	 init_timer1(50,25);
	 start_timer1();
	 delay(1);
	 stop_timer1();
	 return;
}
