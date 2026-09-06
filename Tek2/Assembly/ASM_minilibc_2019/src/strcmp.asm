; ----------------------------------------------------------------------------------------
; strcmp
;        int strcmp(const char *s1, const char *s2);
; ----------------------------------------------------------------------------------------

section .text

global strcmp:

strcmp:
    mov rax, 0
    mov r11, 0
    cmp rdi, 0
    je quit
    cmp rsi, 0
    je quit

while_size:
    mov r10b, byte[rsi + r11]
    cmp byte[rdi + r11], r10b
    jnz diff
    cmp byte[rdi + r11], 0
    je quit
    inc r11
    jmp while_size

diff:
    movzx rax, byte[rdi + r11]
    movzx r11, r10b
    sub rax, r11

quit:
    ret
