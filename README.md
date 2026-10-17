# SIMD_Programming
README

# i.) screenshot of the program output with execution time for all cases

# DEBUG VERSION Visual Studio

# Case: 2^10 x 2^10 Matrix

<img width="356" height="207" alt="image" src="https://github.com/user-attachments/assets/a7838280-20f8-4cbb-b6bf-b0d4d8b54661" />

# Case: 2^13 x 2^13 Matrix

<img width="341" height="212" alt="image" src="https://github.com/user-attachments/assets/977e5305-344c-41d3-8726-79697a432b08" />

# Case: 2^15 x 2^15 Matrix

<img width="355" height="212" alt="image" src="https://github.com/user-attachments/assets/fd73acf9-486d-4b2d-821f-4fc3b89b8697" />

# Case: n=1013 Matrix Boundary test

<img width="602" height="236" alt="image" src="https://github.com/user-attachments/assets/55671495-e79c-495a-8a97-e9bf540188e9" />


# RELEASE VERSION Visual Studio

# Case: 2^10 x 2^10 Matrix

<img width="350" height="212" alt="image" src="https://github.com/user-attachments/assets/3302cc9d-6a32-4a64-b6da-e53f69433da4" />

# Case: 2^13 x 2^13 Matrix

<img width="372" height="220" alt="image" src="https://github.com/user-attachments/assets/44ba6d96-0fd9-41ae-a4e9-2840644cc1f0" />

# Case: 2^15 x 2^15 Matrix

<img width="362" height="217" alt="image" src="https://github.com/user-attachments/assets/2368d8d2-365f-4515-8194-8ea2b759b060" />

# Case: n=1013 Matrix Boundary test

<img width="603" height="245" alt="image" src="https://github.com/user-attachments/assets/37b99155-51a5-4dad-9692-7ba2aab39c09" />


# ii.) comparative table of execution time as well as analysis of the performance of diﬀerent kernels (how many times faster, why is it faster, etc.)

DEBUG (seconds)
| n | C | x86-64 | XMM | YMM |
|---|---|---|---|---|
| 1024 | 0.002191 | 0.000579 | 0.000140 | 0.000101 |
| 8192 | 0.177418 | 0.084402 | 0.039575 | 0.029571 |
| 32768 | 4.439743 | 1.017200 | 0.619246 | 0.598237 |
| 1013 (boundary) | 0.004713 | 0.001278 | 0.000171 | 0.000197 |

RELEASE (seconds)
| n | C | x86-64 | XMM | YMM |
|---|---|---|---|---|
| 1024 | 0.000630 | 0.000612 | 0.000158 | 0.000105 |
| 8192 | 0.047737 | 0.040540 | 0.017793 | 0.015519 |
| 32768 | 1.395032 | 1.097261 | 0.474805 | 0.455065 |
| 1013 (boundary) | 0.001186 | 0.000934 | 0.000268 | 0.000218 |

SPEEDUP OVER C (RELEASE)
| n | x86-64 | XMM | YMM |
|---|---|---|---|
| 1024 | 1.0x | 4.0x | 6.0x |
| 8192 | 1.2x | 2.7x | 3.1x |
| 32768 | 1.3x | 2.9x | 3.1x |
| 1013 | 1.3x | 4.4x | 5.4x |

SPEEDUP OVER C (DEBUG)
| n | x86-64 | XMM | YMM |
|---|---|---|---|
| 1024 | 3.8x | 15.6x | 21.7x |
| 8192 | 2.1x | 4.5x | 6.0x |
| 32768 | 4.4x | 7.2x | 7.4x |
| 1013 | 3.7x | 27.6x | 23.9x |

In Release, YMM is the fastest kernel at every size, followed by XMM, then x86-64, then C. At n = 32768, YMM is about 3.1x faster than C and about 2.4x faster than scalar x86-64. XMM is about 2.9x faster than C. The SIMD kernels are faster because one instruction processes 4 (XMM) or 8 (YMM) floats at once, so fewer instructions run per row. The scalar x86-64 kernel is only about 1.0-1.3x faster than optimized C in Release.

# iii.) screenshot of the program output with correctness check (C)

Case: 2^13 x 2^13 Matrix RELEASE Version

<img width="795" height="82" alt="image" src="https://github.com/user-attachments/assets/aff71575-3178-4bee-be24-f30a5ac881f4" />


<img width="835" height="22" alt="image" src="https://github.com/user-attachments/assets/84875606-c01d-406c-8556-28c3239cab37" />



# iv.) screenshot of the program output, including correctness check (x86-64)

<img width="807" height="82" alt="image" src="https://github.com/user-attachments/assets/9bba7349-369a-4354-b05b-096feb29cdf8" />


<img width="105" height="30" alt="image" src="https://github.com/user-attachments/assets/1a616109-2bce-4b15-9a4c-65f2a5a97cf0" />



# v.) screenshot of the program output, including correctness check (SIMD XMM register)

<img width="783" height="82" alt="image" src="https://github.com/user-attachments/assets/2e0d23c6-4351-4149-b49e-63e5c925bc10" />


<img width="152" height="32" alt="image" src="https://github.com/user-attachments/assets/5b5ce42e-9fc3-49a1-9e43-971d1f884d4e" />




# vi.) screenshot of the program output, including correctness check (SIMD, YMM register)

<img width="812" height="81" alt="image" src="https://github.com/user-attachments/assets/9334d08c-5f35-40e0-be6e-a89f8d904b4b" />

<img width="167" height="27" alt="image" src="https://github.com/user-attachments/assets/c9c144e8-9a0f-4384-a79f-5d314effbdad" />



# vii.) screenshot of boundary check for SIMD XMM and SIMD YMM.
<img width="638" height="625" alt="image" src="https://github.com/user-attachments/assets/50e5adcb-e862-4f30-936c-ebeb2aa72971" />


# viii.) Analyze the results obtained from all platforms. Which one is faster, why is it faster, why speedup is not comparable with the theorical frameworks, etc.

Based on the results, the SIMD implementations using XMM and YMM registers generally performed faster than the C and x86-64 implementations. Among the four kernels, YMM achieved the fastest execution time in all tested cases under Release. This is because SIMD allows multiple floating-point values to be processed in a single instruction. XMM registers can process 4 single-precision floating-point values at a time, while YMM registers can process 8.

For the largest matrix size, (n = 32768 or 2^30), YMM was approximately 3.1x faster than C, while XMM was approximately 2.9x faster. However, the difference between XMM and YMM was relatively small, showing that doubling the register width does not necessarily double the overall performance.

The Debug and Release configurations also showed differences in execution time. Release generally performed faster because compiler optimizations improve the generated machine code. For example, the C implementation for (n = 32768) decreased from 4.44 seconds in Debug to 1.40 seconds in Release. Since the C implementation also benefits from optimization, the speedup of the SIMD kernels relative to C may be smaller in Release than in Debug.

For the boundary case, (n = 1013), both SIMD implementations were faster than C in Release. However, YMM was not always faster than XMM in Debug. Since XMM processes 4 values at a time and YMM processes 8, the remaining elements must be handled separately when the matrix dimension is not a multiple of the vector width.

The measured speedups also differed from theoretical expectations because processing twice as many values per instruction does not mean the entire program will run twice as fast. Other factors, such as memory access, cache behavior, and compiler optimizations, affect the total execution time. Additionally, the C implementation may already benefit from compiler optimizations, making it a stronger baseline for comparison.

Overall, the results show that SIMD can significantly improve performance, especially for larger matrices. YMM generally achieved the best performance, followed closely by XMM, while the x86-64 implementation provided smaller improvements over C.

# ix.) Discuss the problems encountered and solutions made, unique methodology used, AHA moments, etc.

Problems were encountered with switching from the terminal command prompt to Visual Studio. Setting took a lot of trial and error in figuring out how to set up multiple ASM files in Visual Studio. This was eventually fixed by individually creating a new file and adding the custom command line that accesses NASM. The main C file template was originally recording time with a clock header from time.h, but due to the inability to record small values, it resulted in a 0.00000 display of results. This was solved using the QueryPerformanceFrequency timer which uses actual frequencies to time the result, giving much more accurate time data. The compareVector function was originally a 1-to-1 equal sign for comparing two components of the vectors. This means that comparing the vector output of the asm files to c, would result in not equal. We added some tolerance of 0.001 so that results that agree to about 5 digits count as equal.

For the implementation of the SIMD kernels, both use the same idea. The matrix is stored row by row, so each row of A and the vector x can be read straight through in chunks. For every row, we start an accumulator register at zero, load a chunk of the row and the matching chunk of x, multiply them with vmulps, and add the result into the accumulator with vaddps. The XMM kernel handles 4 floats per step and the YMM kernel handles 8. Once the row is done, the accumulator still holds several partial sums, so they have to be added together into one number. In XMM that is two vhaddps instructions. In YMM we first use vextractf128 to pull out the upper half of the register, add it to the lower half with vaddps, and then do the same two vhaddps. The final value is stored in the result vector with vmovss, and the pointer to A moves forward by n floats to start the next row. For boundary handling, both kernels find the number of full chunks by masking n, run the vector loop up to there, and then finish the leftover elements one at a time with a scalar loop. We used vmovups  because the start of each row is not 16-byte or 32-byte aligned when n is not a multiple of 4 or 8.

