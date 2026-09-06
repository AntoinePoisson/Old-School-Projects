; ----------------------------------------------------------------------------------------
; Strchr
;       char *strchr(const char *s, int c);
; ----------------------------------------------------------------------------------------

section .text

global strchr:

strchr:
    mov rax, 0
    cmp rdi, 0
    je error
    cmp byte[rdi], sil
    je end
    cmp byte[rdi], 0
    je error

while:
    inc rdi
    cmp byte[rdi], sil
    je end
    cmp byte[rdi], 0
    je error
    jmp while

end:
    mov rax, rdi
    ret

error:
    mov rax, 0
    ret
