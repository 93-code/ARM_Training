#include <s5pc100.h>

void wdt_init(int sec)
{
	//��ʼ�����Ź�
	WDT.WTCON = (1 << 0) | (3 << 3) | (199 << 8);
	WDT.WTCNT = 2578 * sec;
	WDT.WTDAT = 2578 * sec;

	//ʹ�ܿ��Ź�
	WDT.WTCON |= (1 << 5);
	return;
}

#if 0
if(��ֵ == 1)
{
	//ι��
	WTCNT=100;
}
#endif


void data_abort_handler()
{
	wdt_init(3);
	test_beep();
    while(1);
	return ;
}

void test_wdt()
{
	int *p = (int *)0;

	//����������ֹ�쳣
	//ִ���쳣�����������쳣�������д򿪷����� 3�룬�����帴λ
	*p = 100;

	return ;
}
