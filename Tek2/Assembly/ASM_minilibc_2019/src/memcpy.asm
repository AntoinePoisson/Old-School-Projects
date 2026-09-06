; ----------------------------------------------------------------------------------------
; memcpy
;        void *memcpy(void *dest, const void *src, size_t n);
; ----------------------------------------------------------------------------------------

section .text

global memcpy:

memcpy:
    mov rax, 0
    mov r11, 0
    cmp rdi, 0
    je quit
    cmp rsi, 0
    je quit
    cmp rdx, 0
    je no_copy

while_size:
    mov r10b, byte[rsi + r11]
    mov byte[rdi + r11], r10b
    dec rdx
    inc r11
    cmp rdx, 0
    jnz while_size
    mov rax, rdi

quit:
    ret

no_copy:
    mov rax, rdi
    ret
