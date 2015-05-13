.global _start

_start:
    b reset
	ldr pc,_undefined_instruction
	ldr pc,_software_interrupt
	ldr pc,_prefetch_abort
	ldr pc,_data_abort
	ldr pc,_not_used
	ldr pc,_irq
	ldr pc,_fiq

_undefined_instruction:.word _undefined_instruction
_software_interrupt:.word software_interrupt
_prefetch_abort:.word _prefetch_abort
_data_abort:.word data_abort
_not_used:.word _not_used
_irq:.word irq
_fiq:.word _fiq
_pad:.word 0x12345678

reset:
     @����ARM core�쳣�������λ��
     adr r0,_start
     @��r0��ֵд��CP15.c12�Ĵ���
     @MCR p15, 0, <Rd>, c12, c0, 0
     MCR p15, 0,r0, c12, c0, 0

   	 mov sp,#0x38000
	 bl  main

stop:
	b stop

@�쳣������ȡ�жϺź�����r0�У�Ȼ�󷵻ص�ԭ�ȵ�λ��
software_interrupt:
	ldr sp,=0x36000
	stmfd sp!,{r0-r12,lr}

	@��ȡ���жϺ�
	ldr r0,[lr,#-4];
	mov r1,#0xff
	bic r0,r0,r1,lsl #24

	@����
	ldmfd sp!,{r0-r12,pc}^

@�쳣����
data_abort:
	ldr sp,=0x34000
	stmfd sp!,{r0-r12,lr}

	@�����쳣������
	bl  data_abort_handler

	@����
	ldmfd sp!,{r0-r12,pc}^

irq:
	ldr sp,=0x33000
	sub lr,lr,#4
	stmfd sp!,{r0-r12,lr}

	@����do_irq
	bl  do_irq
	/*
	 * ����ת
	 * ldr lr,=return
	 * ldr pc,=do_irq
	 *
	 *
	 */

return:
	@����
	ldmfd sp!,{r0-r12,pc}^
