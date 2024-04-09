section .text
global main

main:
    mov ebp, esp
    mov eax, 10     ; Push 10 onto stack
    push eax

    mov eax, 20     ; Push 20 onto stack
    push eax

    pop ebx         ; Pop value to ebx
    pop eax         ; Pop next val to eax

    add eax, ebx    ; Add the two values

    mov ecx, eax

    ; exit the program
    mov eax, 1
    xor ebx, ebx
    int 0x80
    