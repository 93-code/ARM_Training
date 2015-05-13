#include <s5pc100.h>

void beep_init()
{
	//初始化GPIO为TOUT_1模式
	GPD.GPDCON &= ~(0xf << 4);
	GPD.GPDCON |=  (0x2 << 4);

	return;
}

void timer1_init(int tcnt_value,int tcmp_value)
{

	/*Timer Input Clock Frequency = PCLK / ( {prescaler value + 1} ) / {divider value}
	 *
	 * prescaler value = 199
	 * divider value   = 16
	 *
	 *
	 * Timer1 In Clock = 66MHZ/(199 + 1)/2
	 *                 = 165000HZ
	 */
	TIMER.TCFG0 &= ~0xff;
	TIMER.TCFG0 |= (199 << 0);
	TIMER.TCFG1 &= ~(0xf << 4);
	TIMER.TCFG1 |= (0x1 << 4);

	//给计数器和比较器赋值
	TIMER1.TCNTB1 = tcnt_value;
	TIMER1.TCMPB1 = tcmp_value;

	//打开手动加载位
	TIMER.TCON |= (1 << 9);

	//清除手动加载位
	TIMER.TCON &= ~(1 << 9);

	return;
}

void timer1_start()
{
	TIMER.TCON |= (1 << 8) | (1 << 11);
	return;
}

void timer1_stop()
{
	TIMER.TCON &= ~(1 << 8);
	return;
}


void test_beep()
{
	 beep_init();
	 timer1_init(500,250);
	 timer1_start();
	 //delay(1);
	 //timer1_stop();
	 return;
}
