.global _start

_start:
	ldr r0,=myarray

	mov r2,#0

cal:
	ldr r1,[r0],#4
	add r2,r2,r1
	cmp r1,#0
	bne cal

stop:
	b stop



myarray:
	.word 0x11
	.word 0x22
	.word 0x33
	.word 0x44
	.word 0
