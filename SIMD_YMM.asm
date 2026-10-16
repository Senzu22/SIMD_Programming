.code
PUBLIC SIMD_YMM
SIMD_YMM PROC
    
    movsxd r9, r9d
    test    r9, r9
    jle     done
    mov     r10, r9
    and     r10, -8
    xor     r11, r11
    
row_loop:
    vxorps  ymm0, ymm0, ymm0
    xor     rax, rax
    test    r10, r10
    jz      reduce
vec_loop:
    vmovups ymm1, ymmword ptr [rcx + rax*4]
    vmovups ymm2, ymmword ptr [rdx + rax*4]
    vmulps  ymm1, ymm1, ymm2
    vaddps  ymm0, ymm0, ymm1
    add     rax, 8
    cmp     rax, r10
    jb      vec_loop
reduce:
    vextractf128 xmm1, ymm0, 1
    vaddps  xmm0, xmm0, xmm1
    vhaddps xmm0, xmm0, xmm0
    vhaddps xmm0, xmm0, xmm0
    cmp     rax, r9
    jge     store
    
tail_loop:
    vmovss  xmm1, dword ptr [rcx + rax*4]
    vmulss  xmm1, xmm1, dword ptr [rdx + rax*4]
    vaddss  xmm0, xmm0, xmm1
    inc     rax
    cmp     rax, r9
    jl      tail_loop
    
store:
    vmovss  dword ptr [r8 + r11*4], xmm0
    lea     rcx, [rcx + r9*4]
    inc     r11
    cmp     r11, r9
    jl      row_loop
    
done:
    vzeroupper
    ret
    
SIMD_YMM ENDP
END