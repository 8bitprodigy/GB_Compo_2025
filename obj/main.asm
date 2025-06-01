;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.1 #15267 (Linux)
;--------------------------------------------------------
	.module main
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _printf
	.globl _vsync
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area _DABS (ABS)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area _HOME
	.area _GSINIT
	.area _GSFINAL
	.area _GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
	G$main$0$0	= .
	.globl	G$main$0$0
	C$main.c$4$0_0$159	= .
	.globl	C$main.c$4$0_0$159
;src/main.c:4: main(void)
;	---------------------------------
; Function main
; ---------------------------------
_main::
	C$main.c$6$1_0$159	= .
	.globl	C$main.c$6$1_0$159
;src/main.c:6: SHOW_BKG;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x01
	ldh	(_LCDC_REG + 0), a
	C$main.c$7$1_0$159	= .
	.globl	C$main.c$7$1_0$159
;src/main.c:7: DISPLAY_ON;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x80
	ldh	(_LCDC_REG + 0), a
	C$main.c$8$1_0$159	= .
	.globl	C$main.c$8$1_0$159
;src/main.c:8: printf("Hello World!");
	ld	de, #___str_0
	push	de
	call	_printf
	pop	hl
	C$main.c$10$1_0$159	= .
	.globl	C$main.c$10$1_0$159
;src/main.c:10: while (1) {
00102$:
	C$main.c$11$2_0$160	= .
	.globl	C$main.c$11$2_0$160
;src/main.c:11: vsync();
	call	_vsync
	C$main.c$13$1_0$159	= .
	.globl	C$main.c$13$1_0$159
;src/main.c:13: }
	C$main.c$13$1_0$159	= .
	.globl	C$main.c$13$1_0$159
	XG$main$0$0	= .
	.globl	XG$main$0$0
	jr	00102$
Fmain$__str_0$0_0$0 == .
___str_0:
	.ascii "Hello World!"
	.db 0x00
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
