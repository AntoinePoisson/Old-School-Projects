; ----------------------------------------------------------------------------------------
; strpbrk
;        char *strpbrk(const char *s, const char *accept);
; ----------------------------------------------------------------------------------------

section .text

global strpbrk:

strpbrk:
    mov rax, 0
    mov r11, 0
    mov r10, 0
    cmp rdi, 0
    je quit
    cmp rsi, 0
    je quit

search_in_second_paramt:
    cmp byte [rdi + r10], 0
    je quit
    cmp byte [rsi + r11], 0
    je while_param_first
    mov r8b, byte [rsi + r11]
    cmp byte [rdi + r10], r8b
    je result
    inc r11
    jmp search_in_second_paramt

while_param_first:
    mov r11, 0
    inc r10
    jmp search_in_second_paramt

find_index:
    dec r10
    inc rdi
    cmp r10, 0
    jnz find_index

result:
    cmp r10, 0
    jnz find_index
    mov rax, rdi

quit:
    ret
