	.arch msp430g2553
	.p2align 1,0
	.text

;;; Button Interrupt
;;; interrupt handler for Port one
	.global Port_1
	.section	__interrupt_vector_3,"ax",@progbits
	.word   Port_1
	.text
Port_1:
	push	r15
	push	r14
	push	r13
	push	r12
	call	#btn_interrupt_handler
	pop	r12
	pop	r13
	pop	r14
	pop	r15
	reti

