	.arch msp430g2553
	.p2align 1,0
	.text

;;; Timer Interrupt
;;; interrupt handler for Timer A0
	.global Timer_0
	.section	__interrupt_vector_10,"ax",@progbits
	.word   Timer_0
	.text
Timer_0:
	push	r15
	push	r14
	push	r13
	push	r12
	call	#timerHandler
	pop	r12
	pop	r13
	pop	r14
	pop	r15
	reti


