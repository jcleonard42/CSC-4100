section .text
global main

main:
    mov ebp, esp; for correct debugging
    mov ecx, 1        ; loop counter
    mov eax, 0        ; sum

loop_start:
    add eax, ecx      ; add current val to sum
    inc ecx           ; increment loop counter
    cmp ecx, 11       ; check if loop counter reached 11
    jne loop_start    ; if not, continue loop

    mov ebx, eax

    ; exit the program
    mov eax, 1
    xor ebx, ebx
    int 0x80
