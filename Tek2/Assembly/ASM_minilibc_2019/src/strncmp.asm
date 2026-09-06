; ----------------------------------------------------------------------------------------
; strncmp
;        int strncmp(const char *s1, const char *s2, size_t n);
; ----------------------------------------------------------------------------------------

section .text

global strncmp:

strncmp:
    mov rax, 0
    mov r11, 0
    mov r10, 0

while_size:
    cmp rdx, 0
    je diff
    mov r10b, byte[rsi + r11]
    cmp byte[rdi + r11], 0
    je diff
    cmp r10b, 0
    je diff
    cmp byte[rdi + r11], r10b
    jne diff
    dec rdx
    inc r11
    jmp while_size

diff:
    movzx rax, byte[rdi + r11]
    movzx r11, byte[rsi + r11]
    sub rax, r11

quit:
    ret