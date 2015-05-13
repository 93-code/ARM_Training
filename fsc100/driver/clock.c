#include <s5pc100.h>

void system_clock_init()
{
	//ʱ��Դѡ��
	CLK_SRC.CLK_SRC0 = (1 << 0) | (1 << 4) | (0 << 16);
	//���÷�Ƶ��
	CLK_DIV.CLK_DIV0 = (1 << 0) | (0 << 4) | (3 << 8) | (1 << 12);
	//����APLL����ʱ��
	PLL_MASK.APLL_MASK = 3600;

#if 0
	The output frequency is calculated by the following equation:
	 FOUT= MDIV X FIN/ (PDIV X 2^SDIV)
	where, MDIV, PDIV, SDIV for APLL and MPLL must meet the following conditions :
	 PDIV: 1 ��PDIV ��63
	 MDIV: 64 ��MDIV ��1023
	 SDIV: 0 ��SDIV ��5
	 Fref(=FIN/ PDIV): 3MHz ��Fref ��6MHz
	 FVCO(=MDIV X FIN/ PDIV): 1000MHz ��FVCO ��2000MHz
	 FOUT: 50MHz ��FVCO ��2000MHz

	 ---------------------------------------------------------
	 FOUT=1334MHZ,FIN=12MHZ
	 MDIV/(PDIV x 2 ^SDIV) = 1334MHZ/12MHZ= 111MHZ

	 SDIV:0

	 MDIV/PDIV=111

	 PDIV->[2,4]:2,3,4
	 MDIV->     222,333,444

	 -----------------------------------------------------------
	 SDIV:0  PDIV:3   MDIV:333
	 FOUT=1332MHZ
#endif
	 //����APLL
	 //APLL_OUT:1332MHZ  SDIV:0  PDIV:3  MDIV:333
	 PLL_CON.APLL_CON = (0 << 0) | (3 << 8) | (333 << 16) | (1 << 31);


	 //--------------------------------------------------------------------
	 //���÷�Ƶ��
	 CLK_DIV.CLK_DIV1 = (1 << 12) | (1 << 16);
	 //����APLL����ʱ��
	 PLL_MASK.MPLL_MASK = 3600;
	 //����MPLL
	 //MPLL_OUT:266MHZ  SDIV:1  PDIV:3  MDIV:133
	 PLL_CON.MPLL_CON = (1 << 0) | (3 << 8) | (133 << 16) | (1 << 31);

	 //������ʱ��ȷ�������ʱ���ź��ȶ�
	 delay(1);

	 return;
}
