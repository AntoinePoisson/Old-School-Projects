; ----------------------------------------------------------------------------------------
; strstr
;        char *strstr(const char *haystack, const char *needle);
; ----------------------------------------------------------------------------------------

section .text

global strstr:

strstr:
    mov rax, 0
    mov r10, -1
    cmp rdi, 0
    je quit
    cmp rsi, 0
    je quit
    cmp byte[rsi], 0
    je no_second_param
    jmp while_str

first_occurrence:
    mov r8b, byte[rsi + r11]
    cmp r8b, 0
    je result
    cmp byte[rdi + r9], r8b
    jnz while_str
    inc r11
    inc r9
    jmp first_occurrence

while_str:
    inc r10
    cmp byte[rdi + r10], 0
    je quit
    mov r11, 0
    mov r9, r10
    mov r8b, byte[rsi]
    cmp byte[rdi + r10], r8b
    je first_occurrence
    jmp while_str

find_index:
    dec r10
    inc rdi
    cmp r10, 0
    jnz find_index


result:
    cmp r10, 0
    jnz find_index
    mov rax, rdi

no_second_param:
    mov rax, rdi

quit:
    ret

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