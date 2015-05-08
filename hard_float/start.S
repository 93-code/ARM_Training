.global _start

#define USER_MODE 0x10

_start:
	@ 设置为所有模式都可以访问协处理器,cortex-A8手册 3.2.27
	mov	r0, #0xfffffff
    mcr	p15, 0, r0, c1, c0, 2

	@ 使能NEON and VFP协处理器,NEON and VFP enable bit.
	@ 设置fpexc的30位为1去使能NEON and VFP,cortex-A8 手册 13.4.3
   	ldr	r0, =1<<30
    fmxr	fpexc, r0

	@设置CPU为user模式
	mov r0,#USER_MODE
	msr cpsr_c,r0

	@跳到main函数
	ldr sp,=0x34000
	bl main

stop:
	b stop
