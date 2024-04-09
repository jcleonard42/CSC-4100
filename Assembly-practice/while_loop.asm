section .text
global main

main:
    mov ebp, esp
    mov ecx, 1        ; loop counter
    mov eax, 0        ; sum

while_loop:
    cmp ecx, 11       ; check if counter reached 11
    jge end_while     ; exit the loop

    add eax, ecx      ; add val to sum
    inc ecx           ; increment counter
    jmp while_loop    ; repeat loop

end_while:
    mov ebx, eax

    ; exit the program
    mov eax, 1
    xor ebx, ebx
    int 0x80
