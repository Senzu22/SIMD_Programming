section .text
global x86Scalar
x86Scalar:
xor r11, r11
L1:
    cmp r11, r9
    jge done
    xorps xmm0, xmm0
    xor rax, rax

L2:
    cmp rax, r9
    jge store

    movss xmm1, [rcx+rax*4]
    movss xmm2, [rdx+rax*4]
    mulss xmm1, xmm2
    addss xmm0, xmm1
    inc rax
    jmp L2

store:
    movss [r8+r11*4], xmm0
    lea rcx, [rcx+r9*4]
    inc r11
    jmp L1

done:
    ret