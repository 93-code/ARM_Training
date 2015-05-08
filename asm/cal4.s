.global _start

_start:
	ldr r1,=0x39000
	ldr r0,=0x18
	bic r0,r1,r0,lsl #12
stop:
	b stop
