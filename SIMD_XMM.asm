section .text
global SIMD_XMM

SIMD_XMM:
    mov r10, r9
    and r10, -4
    xor r11, r11

L1:
    cmp r11, r9
    jge done

    vxorps xmm0, xmm0, xmm0
    xor rax, rax

L2:
    cmp rax, r10
    jge reduce

    vmovups xmm1, [rcx+rax*4]
    vmovups xmm2, [rdx+rax*4]
    vmulps xmm1, xmm1, xmm2
    vaddps xmm0, xmm0, xmm1
    add rax, 4
    jmp L2

reduce:
    vhaddps xmm0, xmm0, xmm0
    vhaddps xmm0, xmm0, xmm0

L3:
    cmp rax, r9
    jge store

    vmovss xmm1, [rcx+rax*4]
    vmovss xmm2, [rdx+rax*4]
    vmulss xmm1, xmm1, xmm2
    vaddss xmm0, xmm0, xmm1
    inc rax
    jmp L3

store:
    vmovss [r8+r11*4], xmm0
    lea rcx, [rcx+r9*4]
    inc r11
    jmp L1

done:
    ret
