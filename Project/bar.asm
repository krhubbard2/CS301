; bar.asm
; Kelby Hubbard
; Started: 2020-10-15
; Updated: 2020-10-24

; For CS 301 Fall 2020
; Assembly Language source code for Assembly Language Programming Project
; Binary to hexadecimal tester

; ***** Assembly Function Prototypes *****
section .text
global foo
global bar
global generate

; ***** EXTERNs *****
extern puts

foo:
mov rdi, welcomeString
call puts
ret

bar:
mov rdi, barString
call puts
ret

; generate function
; Difficulty value is passed into rdi as a long (1 <= value <= 4)
generate:
mov rax, rdi
ret

welcomeString:
	db `This is from foo.\n`,0

barString:
	db `This is from bar.\n`,0

generateString:
	db `This is from generate.\n`,0