; bar.asm
; Kelby Hubbard
; Started: 2020-10-15
; Updated: 2020-11-08

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
extern srand
extern rand
extern time

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
cmp rdi, 2
je twoDiff
cmp rdi, 3
je threeDiff
cmp rdi, 4
je fourDiff

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


welcomeString:
	db `This is from foo.\n`,0

barString:
	db `This is from bar.\n`,0

generateString:
	db `This is from generate.\n`,0