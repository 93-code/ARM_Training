/*
 * asml.s
 *
 *  Created on: 2015-5-6
 *      Author: Administrator
 */

.global _start

_start:
	mov r0,#0
	mov r1,#20
	mov	r2,#30
	mov	r3,#40

stop:
	b stop
