/*
 * cal2.s
 *
 *  Created on: 2015-5-6
 *      Author: Administrator
 */

.global _start

_start:

	mov r0,#10
	mov r1,#20

	cmp r0,r1
	addgt r0,r0,r1
	@cmp r0,r1
	suble r0,r0,r1

stop:
	b stop
