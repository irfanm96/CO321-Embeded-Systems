	.file	"q2.c"
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__SREG__ = 0x3f
__tmp_reg__ = 0
__zero_reg__ = 1
	.section	.text.startup,"ax",@progbits
.global	main
	.type	main, @function
main:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	cbi 0xa,2
	ldi r24,lo8(63)
	out 0x4,r24
	lds r24,105
	ori r24,lo8(2)
	sts 105,r24
	lds r24,105
	ori r24,lo8(1)
	sts 105,r24
/* #APP */
 ;  18 "q2.c" 1
	sei
 ;  0 "" 2
/* #NOAPP */
	sbi 0x1d,0
.L2:
	rjmp .L2
	.size	main, .-main
	.text
.global	__vector_1
	.type	__vector_1, @function
__vector_1:
	push r1
	push r0
	in r0,__SREG__
	push r0
	clr __zero_reg__
	push r24
/* prologue: Signal */
/* frame size = 0 */
/* stack size = 4 */
.L__stack_usage = 4
	in r24,0x5
	subi r24,lo8(-(1))
	out 0x5,r24
/* epilogue start */
	pop r24
	pop r0
	out __SREG__,r0
	pop r0
	pop r1
	reti
	.size	__vector_1, .-__vector_1
	.ident	"GCC: (GNU) 5.4.0"
