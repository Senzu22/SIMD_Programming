# SIMD_Programming
README

i.) screenshot of the program output with execution time for all cases

DEBUG VERSION Visual Studio

<img width="356" height="207" alt="image" src="https://github.com/user-attachments/assets/a7838280-20f8-4cbb-b6bf-b0d4d8b54661" />

<img width="341" height="212" alt="image" src="https://github.com/user-attachments/assets/977e5305-344c-41d3-8726-79697a432b08" />

<img width="355" height="212" alt="image" src="https://github.com/user-attachments/assets/fd73acf9-486d-4b2d-821f-4fc3b89b8697" />

<img width="602" height="236" alt="image" src="https://github.com/user-attachments/assets/55671495-e79c-495a-8a97-e9bf540188e9" />


RELEASE VERSION Visual Studio

<img width="350" height="212" alt="image" src="https://github.com/user-attachments/assets/3302cc9d-6a32-4a64-b6da-e53f69433da4" />

<img width="372" height="220" alt="image" src="https://github.com/user-attachments/assets/44ba6d96-0fd9-41ae-a4e9-2840644cc1f0" />

<img width="362" height="217" alt="image" src="https://github.com/user-attachments/assets/2368d8d2-365f-4515-8194-8ea2b759b060" />

<img width="603" height="245" alt="image" src="https://github.com/user-attachments/assets/37b99155-51a5-4dad-9692-7ba2aab39c09" />


ii.) comparative table of execution time as well as analysis of the performance of diﬀerent kernels (how many times faster, why is it faster, etc.)

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
| 1024 | 0.002191 | 0.000579 | 0.000140 | 0.000101 |
| 8192 | 0.177418 | 0.084402 | 0.039575 | 0.029571 |
| 32768 | 4.439743 | 1.017200 | 0.619246 | 0.598237 |
| 1013 (boundary) | 0.004713 | 0.001278 | 0.000171 | 0.000197 |

SPEEDUP OVER C (DEBUG)
| n | x86-64 | XMM | YMM |
|---|---|---|---|
| 1024 | 1.0x | 4.0x | 6.0x |
| 8192 | 1.2x | 2.7x | 3.1x |
| 32768 | 1.3x | 2.9x | 3.1x |
| 1013 | 1.3x | 4.4x | 5.4x |

SPEEDUP OVER C (RELEASE)
| n | x86-64 | XMM | YMM |
|---|---|---|---|
| 1024 | 3.8x | 15.6x | 21.7x |
| 8192 | 2.1x | 4.5x | 6.0x |
| 32768 | 4.4x | 7.2x | 7.4x |
| 1013 | 3.7x | 27.6x | 23.9x |

In Release, YMM is the fastest kernel at every size, followed by XMM, then x86-64, then C. At n = 32768, YMM is about 3.1x faster than C and about 2.4x faster than scalar x86-64. XMM is about 2.9x faster than C. The SIMD kernels are faster because one instruction processes 4 (XMM) or 8 (YMM) floats at once, so fewer instructions run per row. The scalar x86-64 kernel is only about 1.0-1.3x faster than optimized C in Release.

iii.) screenshot of the program output with correctness check (C)

Case: 2^13 x 2^13 Matrix RELEASE Version

<img width="795" height="82" alt="image" src="https://github.com/user-attachments/assets/aff71575-3178-4bee-be24-f30a5ac881f4" />

<img width="835" height="22" alt="image" src="https://github.com/user-attachments/assets/84875606-c01d-406c-8556-28c3239cab37" />



iv.) screenshot of the program output, including correctness check (x86-64)

<img width="807" height="82" alt="image" src="https://github.com/user-attachments/assets/9bba7349-369a-4354-b05b-096feb29cdf8" />

<img width="105" height="30" alt="image" src="https://github.com/user-attachments/assets/1a616109-2bce-4b15-9a4c-65f2a5a97cf0" />



v.) screenshot of the program output, including correctness check (SIMD XMM register)

<img width="783" height="82" alt="image" src="https://github.com/user-attachments/assets/2e0d23c6-4351-4149-b49e-63e5c925bc10" />

<img width="152" height="32" alt="image" src="https://github.com/user-attachments/assets/5b5ce42e-9fc3-49a1-9e43-971d1f884d4e" />




vi.) screenshot of the program output, including correctness check (SIMD, YMM register)

<img width="812" height="81" alt="image" src="https://github.com/user-attachments/assets/9334d08c-5f35-40e0-be6e-a89f8d904b4b" />

<img width="167" height="27" alt="image" src="https://github.com/user-attachments/assets/c9c144e8-9a0f-4384-a79f-5d314effbdad" />



vii.) screenshot of boundary check for SIMD XMM and SIMD YMM.
<img width="638" height="625" alt="image" src="https://github.com/user-attachments/assets/50e5adcb-e862-4f30-936c-ebeb2aa72971" />


viii.) Analyze the results obtained from all platforms. Which one is faster, why is it faster, why speedup is not comparable with the theorical frameworks, etc.



ix.) Discuss the problems encountered and solutions made, unique methodology used, AHA moments, etc.


