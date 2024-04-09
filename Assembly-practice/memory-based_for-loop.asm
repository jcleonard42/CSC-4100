section .text
global main

main:
    mov ebp, esp
    mov dword [counter], 1   ; loop counter
    mov dword [sum], 0       ; sum

loop_start:
    mov eax, [counter]      ; move counter to eax
    add dword [sum], eax    ; add value to sum
    inc dword [counter]     ; increment counter
    cmp dword [counter], 11 ; check if counter reached 11
    jne loop_start          ; if not 11

    mov ebx, dword [sum]    ; store sum in ebx

    ; exit the program
    mov eax, 1
    xor ebx, ebx
    int 0x80

section .bss
counter resd 1  ; reserve counter memory
sum resd 1      ; reserve sum memory
