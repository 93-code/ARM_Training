.global _start

_start:
	mov r0,#11
	mov r1,#12

	b main

stop:
	b stop
