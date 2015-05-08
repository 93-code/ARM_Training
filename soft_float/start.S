.global _start

#define USER_MODE 0x10

_start:
	@设置CPU为user模式
	mov r0,#USER_MODE
	msr cpsr_c,r0

	@跳到main函数
	ldr sp,=0x34000
	bl main

stop:
	b stop
