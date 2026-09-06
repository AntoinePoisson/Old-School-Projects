; ----------------------------------------------------------------------------------------
; strcmp
;        int strcmp(const char *s1, const char *s2);
; ----------------------------------------------------------------------------------------

section .text

global memmove:

memmove:
    mov rax, 0
    ret
;    mov r11, 0
;    cmp rdi, 0
;    je quit
;    cmp rsi, 0
;    je quit
;
;while_size:
;    mov r10b, byte[rsi + r11]
;    cmp byte[rdi + r11], r10b
;    jnz diff
;    cmp byte[rdi + r11], 0
;    je quit
;    inc r11
;    jmp while_size
;
;diff:
;    movzx rax, byte[rdi + r11]
;    movzx r11, r10b
;    sub rax, r11
;
;quit:
;    ret
;
;
; 1 parameter : rdi
; 2 parameter : rsi
; 3 parameter : rdx



;display:
;    mov rax, 9
;    add rdi, rax
;    mov rsi, rdi
;    mov rax, 1
;    mov rdi, 1
;    mov rdx, 8
;    syscall

;section .rodata
;  msg: db "Hello, world!", 10
;  msglen: equ $ - msg

;global strlen:


;strlen:
    ; mov rax, counter
;    mov ESI, -1

;counter:
;    inc ESI
;    cmp rdi, 0
;    jnz counter
;    mov rax, ESI
;    ret

    
    ; premier parametre rdi
    ; retour rax

    ; mov rdi, 1
    ; mov rsi, 
    ; mov rdx, 



; global _start

; section .text

; _start:
;   mov rax, 1        ; write(
;   mov rdi, 1        ;   STDOUT_FILENO,
;   mov rsi, msg      ;   "Hello, world!\n",
;   mov rdx, msglen   ;   sizeof("Hello, world!\n")
;   syscall           ; );

;   mov rax, 60       ; exit(
;   mov rdi, 0        ;   EXIT_SUCCESS
;   syscall           ; );

; section .rodata
;   msg: db "Hello, world!", 10
;   msglen: equ $ - msg