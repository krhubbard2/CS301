; bar.asm
; Kelby Hubbard
; Started: 2020-10-15
; Updated: 2020-11-25

; For CS 301 Fall 2020
; Assembly Language source code for Assembly Language Programming Project
; Binary to hexadecimal tester

; ***** Assembly Function Prototypes *****
section .text
global generate
global resultOutputStartup
global generateButtonClick
global correctString
global wrongString

; ***** EXTERNs *****
extern srand
extern rand
extern time

; generate
; Difficulty value is passed into rdi as a long (1 <= value <= 4)
; Generates a random number based off of difficulty level selected
generate:

cmp rdi, 2
je twoDiff
cmp rdi, 3
je threeDiff
cmp rdi, 4
je fourDiff

	; Difficulty level 1
	oneDiff:
		mov rdi, 0
		call time ; For srand use
		mov rdi, rax
		call srand ; To use random (clock) seed 
		call rand ; rax contains random number

		; rand max = 31 
		mov rdx, 0
		mov rcx, 32
		div rcx

		; return rand num
		mov rax, rdx
		ret


	; Difficulty level 2
	twoDiff:
		mov rdi, 0
		call time ; For srand use
		mov rdi, rax
		call srand ; To use random (clock) seed 
		call rand ; rax contains random number

		; rand max = 63
		mov rdx, 0
		mov rcx, 64
		div rcx

		; return rand num
		mov rax, rdx
		ret


	; Difficulty level 3
	threeDiff:
		mov rdi, 0
		call time ; For srand use
		mov rdi, rax
		call srand ; To use random (clock) seed 
		call rand ; rax contains random number

		; rand max = 127
		mov rdx, 0
		mov rcx, 128
		div rcx

		; return rand num
		mov rax, rdx
		ret


	; Difficulty level 4
	fourDiff:
		mov rdi, 0
		call time ; For srand use
		mov rdi, rax
		call srand ; To use random (clock) seed 
		call rand ; rax contains random number

		; rand max = 255
		mov rdx, 0
		mov rcx, 256
		div rcx

		; return rand num
		mov rax, rdx
		ret

; String to be passed to FLTK Result Output Box (child 5)
; Sring displayed on start up
resultOutputStartup:
	mov rax, ROSstring
	ret

; String to be passed to FLTK Result Output Box (child 5)
; String displayed after FLTK Generate Button (child 1) is pressed
generateButtonClick:
	mov rax, GBCstring
	ret

; String to be passed to FLTK Result Output Box (child 5)
; String displayed after correct guess
correctString:
	mov rax, Cstring
	ret

; String to be passed to FLTK Result Output Box (child 5)
; String displayed after incorrect guess
wrongString:
	mov rax, Wstring
	ret


; ***** strings *****

ROSstring:
	db `First click "Generate"`,0

GBCstring:
	db `Enter your guess then submit.`,0

Cstring:
	db `Correct!`,0

Wstring:
	db `Wrong.`,0