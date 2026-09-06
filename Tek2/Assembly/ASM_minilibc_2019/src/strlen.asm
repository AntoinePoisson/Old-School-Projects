; ----------------------------------------------------------------------------------------
; Strlen
;       size_t strlen(const char *s);
; ----------------------------------------------------------------------------------------

section .text

global strlen:

strlen:
    mov rax, 0
    cmp rdi, 0
    je end
    cmp byte[rdi], 0
    je end


counter_size:
    inc rax
    add rdi, 1
    cmp byte[rdi], 0
    jnz counter_size

end:
    ret