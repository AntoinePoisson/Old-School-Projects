; ----------------------------------------------------------------------------------------
; strcasecmp
;        int strcasecmp(const char *s1, const char *s2);
; ----------------------------------------------------------------------------------------

section .text

global strcasecmp:

strcasecmp:
    mov rax, 0
    mov r11, 0
    mov r10, 0
    mov r9, 0
    cmp rdi, 0
    je quit
    cmp rsi, 0
    je quit

first_param_maj:
    mov r10b, byte[rdi + r9]
    cmp r10b, 65
    jl second_param_maj
    cmp r10b, 90
    jg second_param_maj
    add r10b, 32

second_param_maj:
    mov r11b, byte[rsi + r9]
    cmp r11b, 65
    jl while_size
    cmp r11b, 90
    jg while_size
    add r11b, 32

while_size:
    cmp r11b, r10b
    jnz diff
    cmp r11b, 0
    je quit
    inc r9
    jmp first_param_maj
    
diff:
    movzx rax, r10b
    sub rax, r11

quit:
    ret
