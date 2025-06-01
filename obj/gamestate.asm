;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.1 #15267 (Linux)
;--------------------------------------------------------
	.module gamestate
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _free
	.globl _malloc
	.globl _printf
	.globl _GameState_init
	.globl _GameState_new
	.globl _GameState_free
	.globl _GameState_run
	.globl _GameState_update
	.globl _GameState_draw
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
	G$GameState_init$0$0	= .
	.globl	G$GameState_init$0$0
	C$gamestate.c$19$0_0$164	= .
	.globl	C$gamestate.c$19$0_0$164
;src/gamestate.c:19: GameState_init(GameState *game_state)
;	---------------------------------
; Function GameState_init
; ---------------------------------
_GameState_init::
	C$gamestate.c$22$0_0$164	= .
	.globl	C$gamestate.c$22$0_0$164
;src/gamestate.c:22: }
	C$gamestate.c$22$0_0$164	= .
	.globl	C$gamestate.c$22$0_0$164
	XG$GameState_init$0$0	= .
	.globl	XG$GameState_init$0$0
	ret
	G$GameState_new$0$0	= .
	.globl	G$GameState_new$0$0
	C$gamestate.c$29$0_0$166	= .
	.globl	C$gamestate.c$29$0_0$166
;src/gamestate.c:29: GameState_new(void)
;	---------------------------------
; Function GameState_new
; ---------------------------------
_GameState_new::
	C$gamestate.c$31$1_0$166	= .
	.globl	C$gamestate.c$31$1_0$166
;src/gamestate.c:31: GameState *game_state = malloc(sizeof(GameState));
	ld	de, #0x0002
	call	_malloc
	C$gamestate.c$32$2_0$167	= .
	.globl	C$gamestate.c$32$2_0$167
;src/gamestate.c:32: if (!game_state) {
	ld	a, b
	or	a, c
	jr	NZ, 00102$
	C$gamestate.c$33$3_0$168	= .
	.globl	C$gamestate.c$33$3_0$168
;src/gamestate.c:33: printf("Could not allocate game_state!");
	ld	de, #___str_0
	push	de
	call	_printf
	pop	hl
	C$gamestate.c$34$3_0$168	= .
	.globl	C$gamestate.c$34$3_0$168
;src/gamestate.c:34: return NULL;
	ld	bc, #0x0000
	ret
00102$:
	C$gamestate.c$37$1_0$166	= .
	.globl	C$gamestate.c$37$1_0$166
;src/gamestate.c:37: GameState_init(game_state);
	push	bc
	ld	e, c
	ld	d, b
	call	_GameState_init
	pop	bc
	C$gamestate.c$39$1_0$166	= .
	.globl	C$gamestate.c$39$1_0$166
;src/gamestate.c:39: return game_state;
	C$gamestate.c$40$1_0$166	= .
	.globl	C$gamestate.c$40$1_0$166
;src/gamestate.c:40: }
	C$gamestate.c$40$1_0$166	= .
	.globl	C$gamestate.c$40$1_0$166
	XG$GameState_new$0$0	= .
	.globl	XG$GameState_new$0$0
	ret
Fgamestate$__str_0$0_0$0 == .
___str_0:
	.ascii "Could not allocate game_state!"
	.db 0x00
	G$GameState_free$0$0	= .
	.globl	G$GameState_free$0$0
	C$gamestate.c$47$1_0$170	= .
	.globl	C$gamestate.c$47$1_0$170
;src/gamestate.c:47: GameState_free(GameState *game_state)
;	---------------------------------
; Function GameState_free
; ---------------------------------
_GameState_free::
	C$gamestate.c$49$1_0$170	= .
	.globl	C$gamestate.c$49$1_0$170
;src/gamestate.c:49: free(game_state);
	C$gamestate.c$50$1_0$170	= .
	.globl	C$gamestate.c$50$1_0$170
;src/gamestate.c:50: }
	C$gamestate.c$50$1_0$170	= .
	.globl	C$gamestate.c$50$1_0$170
	XG$GameState_free$0$0	= .
	.globl	XG$GameState_free$0$0
	jp	_free
	G$GameState_run$0$0	= .
	.globl	G$GameState_run$0$0
	C$gamestate.c$57$1_0$172	= .
	.globl	C$gamestate.c$57$1_0$172
;src/gamestate.c:57: GameState_run(GameState *game_state)
;	---------------------------------
; Function GameState_run
; ---------------------------------
_GameState_run::
	push	de
	C$gamestate.c$60$1_0$172	= .
	.globl	C$gamestate.c$60$1_0$172
;src/gamestate.c:60: while (1) {
00102$:
	C$gamestate.c$61$2_0$173	= .
	.globl	C$gamestate.c$61$2_0$173
;src/gamestate.c:61: GameState_update(game_state);
	pop	de
	push	de
	call	_GameState_update
	C$gamestate.c$62$2_0$173	= .
	.globl	C$gamestate.c$62$2_0$173
;src/gamestate.c:62: GameState_draw(game_state);
	pop	de
	push	de
	call	_GameState_draw
	jr	00102$
	C$gamestate.c$64$1_0$172	= .
	.globl	C$gamestate.c$64$1_0$172
;src/gamestate.c:64: }
	inc	sp
	inc	sp
	C$gamestate.c$64$1_0$172	= .
	.globl	C$gamestate.c$64$1_0$172
	XG$GameState_run$0$0	= .
	.globl	XG$GameState_run$0$0
	ret
	G$GameState_update$0$0	= .
	.globl	G$GameState_update$0$0
	C$gamestate.c$68$1_0$176	= .
	.globl	C$gamestate.c$68$1_0$176
;src/gamestate.c:68: GameState_update(GameState *game_state)
;	---------------------------------
; Function GameState_update
; ---------------------------------
_GameState_update::
	C$gamestate.c$72$1_0$176	= .
	.globl	C$gamestate.c$72$1_0$176
;src/gamestate.c:72: }
	C$gamestate.c$72$1_0$176	= .
	.globl	C$gamestate.c$72$1_0$176
	XG$GameState_update$0$0	= .
	.globl	XG$GameState_update$0$0
	ret
	G$GameState_draw$0$0	= .
	.globl	G$GameState_draw$0$0
	C$gamestate.c$76$1_0$179	= .
	.globl	C$gamestate.c$76$1_0$179
;src/gamestate.c:76: GameState_draw(GameState *game_state)
;	---------------------------------
; Function GameState_draw
; ---------------------------------
_GameState_draw::
	C$gamestate.c$79$1_0$179	= .
	.globl	C$gamestate.c$79$1_0$179
;src/gamestate.c:79: }
	C$gamestate.c$79$1_0$179	= .
	.globl	C$gamestate.c$79$1_0$179
	XG$GameState_draw$0$0	= .
	.globl	XG$GameState_draw$0$0
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
