section .text
global main
main:
    mov ebp, esp     ; for correct debugging
    mov eax, 10      ; n1
    mov ebx, 20      ; n2
    mov ecx, 40      ; n3
    xor edx, edx     ; large = 0

    ; if n1 is greater than both n2 and n3, n1 is the largest
    cmp eax, ebx
    jge n1_greater_than_n2
    cmp eax, ecx
    jge n1_greater_than_n3
    jmp end_if_n1_not_largest

n1_greater_than_n2:
    cmp eax, ecx
    jge n1_is_largest
    jmp end_if_n1_not_largest

n1_greater_than_n3:
    jmp n1_is_largest

n1_is_largest:
    mov edx, eax
    jmp end_if_n1_not_largest

end_if_n1_not_largest:
    mov ebx, edx

    ; exit the program
    mov eax, 1
    xor ebx, ebx
    int 0x80
