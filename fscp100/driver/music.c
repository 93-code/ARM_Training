int tone[][2]= {
	    0xff,0xff,//ռλ

	    /*��1-7*/
		629,314,//Do 1
		561,281,//Re 2
		500,250,//Mi 3
		473,236,//Fa 4
		421,210,//SO 5
		375,188,//La 6
		334,167,//Si 7

		/*��1-7*/
		315,158,//Do 8 1
		281,141,//Re 9 2
		250,125,//Mi a 3
		236,118,//Fa b 4
		210,105,//So c 5
		187, 94,//La d 6
		167, 84,//Si e 7
};

unsigned char zbjbxf[]={
		0x64,0xA3,0xC1,0xA2,0x62,0x84,0x61,0x81,0x61,
		0xA4,0xA1,0x91,0xA1,0x81,0x64,0xA3,0xC1,0xD2,
		0xD2,0xD2,0xA2,0xC4,0xA1,0xC1,0xA1,0xC1,0xD2,
		0xD2,0xD2,0xA2,0xC4,0xC2,0x62,0xC2,0x62,0xA2,
		0xA2,0x84,0x94,0x94,0x92,0x81,0x91,0xA2,0xC2,
		0xD4,0xE4,0xA4,0xE4,0xA2,0xE2,0xA2,0xE2,0xA2,
		0xA2,0x84,0x94,0x94,0x92,0x81,0x91,0xA2,0xC2,
		0xD8
};
unsigned char hktk[]={ 0x24,0x03, 0x20,0x02, 0x1F,0x02, 0x25,0x03, 0x24,0x03,
        0x22,0x02, 0x23,0x02, 0x1F,0x02, 0x1F,0x16, 0x22,0x03,
        0x23,0x03, 0x1F,0x02, 0x1F,0x16, 0x22,0x04, 0x23,0x03,
        0x20,0x02, 0x1F,0x02, 0x1F,0x02, 0x25,0x03, 0x20,0x02,
        0x21,0x02, 0x20,0x02, 0x1F,0x16, 0x20,0x02, 0x21,0x02,
        0x23,0x02, 0x23,0x02, 0x23,0x02, 0x23,0x02, 0x24,0x03,
        0x23,0x02, 0x24,0x03, 0x25,0x03, 0x1F,0x02, 0x1F,0x02,
        0x1F,0x02, 0x1F,0x02, 0x1F,0x02, 0x1F,0x02, 0x25,0x03,
        0x24,0x04, 0x23,0x03, 0x24,0x03, 0x24,0x03, 0x00,0x00};

int play_tone(unsigned char index,unsigned char beat)
{
	init_beep();
	init_timer1(tone[index][0],tone[index][1]);
	start_timer1();

	mdelay(beat * 75);
	stop_timer1();
	mdelay(3);

	return  0;
}
<<<<<<< HEAD
int play_tone_on(unsigned char index)
{
	init_beep();
	init_timer1(tone[index][0],tone[index][1]);
	start_timer1();

	return  0;
}

int play_tone_off()
{
	stop_timer1();

	return 0;
}
=======
>>>>>>> e5522cd... Update arm

int play_music()
{
	int i = 0;
	unsigned char index,beat;
	unsigned char *p = hktk;

	for(i = 0;i < sizeof(zbjbxf)/sizeof(char);i ++)
	{
		index = p[i] >> 4;
		beat  = p[i] & 0xf;
		play_tone(index, beat);
	}

	return 0;
}
