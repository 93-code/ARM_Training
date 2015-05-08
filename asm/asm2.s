.global _start

_start: b reset
	ldr pc, _undefined_instruction
	ldr pc, _software_interrupt
	ldr pc, _prefetch_abort
	ldr pc, _data_abort
	ldr pc, _not_used
	ldr pc, _irq
	ldr pc, _fiq

_undefined_instruction: .word _undefined_instruction
_software_interrupt: 	.word software_interrupt
_prefetch_abort:		.word _prefetch_abort
_data_abort:			.word _data_abort
_not_used:				.word _not_used
_irq:					.word _irq
_fiq:					.word _fiq
_pad:					.word 0x12345678

reset:
	adr r0, _start
	MCR p15, 0, r0, c12, c0, 0

	mov r0, #12
	mov r1, #22
	swi #8
	mov r2, #40

stop:
	b stop

software_interrupt:
	ldr sp, =0x38000
	stmfd sp!, {r0-r12, lr}

	ldr r0,[lr, #-4];
	mov r1, #0xff
	bic r0, r0, r1, lsl #24

	ldmfd sp!,{r0-r12, pc}^
