.global mycopy
.global _start

_start:
	mov sp, #0x38000
	bl main
	mov r3, #10
	mov r4, #20
stop:
	b stop

mycopy:
	LDRB r2, [r1], #1
	STRB r2, [r0], #1
	CMP r2, #0
	BNE mycopy
	mov pc, lr
