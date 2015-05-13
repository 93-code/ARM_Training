#define GPG3CON  0xE03001C0
#define GPG3DAT  0xE03001C4

void led_init(int n)
{
	int i;
	int *p = (int *)GPG3CON;

	if(n < 1 || n > 4)
		return;

	//设为输出模式
	for(i = 0;i < n;i ++)
	{
		*p &= ~(0xf << i * 4);
		*p |=  (1   << i * 4);
	}

	return;
}

void led_on(int n)
{
	int i;
	int *p = (int *)GPG3DAT;

	if(n < 1 || n > 4)
		return;

	//输出高电平
	*p |= (1 << (n - 1));


	return;
}

void led_off(int n)
{
	int *p = (int *)GPG3DAT;

	if(n < 1 || n > 4)
		return;

	//输出低电平
	*p &= ~(1 << (n - 1));

	return;
}

int water_led()
{
	int i = 0;

	led_init(4);

	while(1)
	{
		for(i = 1;i <= 4;i ++)
		{
			led_on(i);
			delay(1);
			led_off(i);
			//GPGDAT = (1 << (i - 1));
		}
	}

	return 0;
}
