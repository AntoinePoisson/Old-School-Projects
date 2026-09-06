; ----------------------------------------------------------------------------------------
; rindex
;        char *rindex(const char *s, int c);
; ----------------------------------------------------------------------------------------

section .text

global rindex:

rindex:
    mov rax, 0
    mov r11, 0
    mov r10, -1
    cmp rdi, 0
    je quit
    jmp while_size

save_index:
    mov r10, r11
    cmp byte[rdi + r11], 0
    je end
    inc r11

while_size:
    cmp byte[rdi + r11], sil
    je save_index
    cmp byte[rdi + r11], 0
    je end
    inc r11
    jmp while_size
    
end:
    cmp r10, -1
    je quit
    mov r11, 0
    cmp r11, r10
    je result

return_adress:
    inc rdi
    inc r11
    cmp r11, r10
    jnz return_adress

result:
    mov rax, rdi

quit:
    ret
