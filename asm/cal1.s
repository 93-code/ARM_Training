/*
 * cal1.s
 *
 *  Created on: 2015-5-6
 *      Author: Administrator
 */

.global _start

_start:

	ldr r0,=0xabcd
	bic r0,r0,#0xf

	mov r1,#0xf
	bic r0,r0,r1,lsl #8
	mov r1,#0xa

	orr r0,r0,r1,lsl #8


stop:
	b stop
