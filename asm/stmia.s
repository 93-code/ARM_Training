.global _start

_start:
	mov r0,#1
	mov r1,#2
	mov r3,#3

	mov r4,#0x24000
	stmia r4!,{r0,r1,r3}

	ldmdb r4!,{r5,r6,r7}
stop:
	b stop
