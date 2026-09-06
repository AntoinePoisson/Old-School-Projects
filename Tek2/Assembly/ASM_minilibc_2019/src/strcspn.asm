; ----------------------------------------------------------------------------------------
; Strcspn
;       size_t strcspn(const char *s, const char *reject);
; ----------------------------------------------------------------------------------------

section .text

global strcspn:

strcspn:
    mov rax, 0
    cmp rdi, 0
    je end
    cmp byte[rdi], 0
    je end
    jmp counter_size

check_string:
    inc r10
    mov r11b, byte[rsi + r10]
    cmp byte[rdi], r11b
    je end
    cmp byte[rsi + r10], 0
    je continue
    jmp check_string

continue:
    add rdi, 1
    inc rax

counter_size:
    cmp byte[rdi], 0
    je end
    mov r10, -1
    jmp check_string

end:
    ret