; ----------------------------------------------------------------------------------------
; memset
;       void *memset(void *s, int c, size_t n);
; ----------------------------------------------------------------------------------------

section .text

global memset:

memset:
    mov rax, 0
    mov r11, 0
    cmp rdi, 0
    je quit
    cmp rdx, 0
    je no_copy

while_size:
    mov byte[rdi + r11], sil
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
