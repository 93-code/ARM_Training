/*
 * cal.s
 *
 *  Created on: 2015-5-6
 *      Author: Administrator
 */

.global _start

_start:

	ldr r0,=345
	mov r1,#2
	mul r0,r1,r0
	add r0,r0,#1
	ldr r1,=128
	sub r0,r0,r1,lsr #2

stop:
	b stop
