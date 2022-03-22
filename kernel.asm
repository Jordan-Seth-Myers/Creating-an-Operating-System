;Jordan Myers
;boot2.S 
;Aseembly Code OS

BITS 32

GLOBAL k_print
     

k_print:
    ;setting up registers 
    ;pushing registers onto the stack

    push ebp     ; base pointer register
    mov ebp, esp
    push eax      ; col
    push ebx      ; row
    push esi      ;source index string operation
    push edi      ;destination index string operation
    push ecx
    push edx


    ;algorithm 
    mov ecx, [ebp + 20]    ; column 
    mov ebx, [ebp + 16]    ; row
    mov eax, [ebp + 12]    ; string length integer
    mov esi, [ebp + 8]     ;moving address string into esi

    ;math for offset
    imul ebx, 80           ;for (row * 80)
    add ebx, ecx           ;for (row * 80 + col)
    imul ebx, 2            ;for 2*(row * 80 + col)
    mov edi, ebx
    mov edx, 0xB8000       ;adding 0xB000 to ^
    add edi, edx           ;moving offset edx into edi

printLoop:
    cmp edi, 0xB8FA0  ;if edi > 0xB8000 +2(24*80+79) 
    jge finish

    cmp eax, 0          ; compare eax to 0
    je finish

    cld                 ;clears direction flag 

    movsb                  ;ds:edi  es:edi
    mov BYTE [edi], 31     ; changes the color of
    inc edi                ;inc the space
    dec eax
    jmp printLoop

finish: 
    pop edx
    pop ecx
    pop edi
    pop esi
    pop ebx
    pop eax
    pop ebp
    ret


    




