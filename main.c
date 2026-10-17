#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

extern void x86Scalar(float* A, float* v, float* result, long long n);
extern void SIMD_XMM(float* A, float* v, float* result, long long n);
extern void SIMD_YMM(float* A, float* v, float* result, long long n);

#define REPEAT 30
static const long long TEST_SIZES[] = {1024, 8192, 32768};
static const int NUM_TEST_SIZES = 3;
static const int BOUNDARY_SIZE = 1013;

void MultMatrixVector(float* A, float* v, float* result, long long n){
    for(int i = 0; i < n; i++){
        float sum = 0.0f;
        for(int j=0; j < n; j++){
            sum += A[i * n + j] * v[j];
        }
        result[i] = sum;
    }
}

void InitializeData(float* A, float* v, long long n){
    for(int i = 0; i < n; i++){
        v[i] = sinf(i*0.001f);
        for(int j =0; j < n; j++){
            A[i * n + j] = cosf((i * n + j) * 0.001f);
        }
    }
}

typedef void(*Kernel)(float*, float*, float*, long long);

double TimeKernel(Kernel kernel, float* A, float* x, float* y, long long n) {
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&start);
    for (int r = 0; r < REPEAT; r++) {
        kernel(A, x, y, n);
    }
    QueryPerformanceCounter(&end);

    double totalSeconds = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
    return totalSeconds / REPEAT;
}


int CompareVectors(float* reference, float* actual, long long n){
    int equal = 1;
    for (int i = 0; i < n; i++) 
    {
        if (fabsf(reference[i] - actual[i]) > 1e-3f * fmaxf(1.0f, fabsf(reference[i])))
        {
            equal = 0;
            break;
        }
    }
	
    if(equal)
    {
        printf("Equal\n");
    } else {
        printf("Not Equal\n");
    }
    return equal;
}

void DisplayFirstLast5(const char* label, float *v, long long n){
    printf("%s\n", label);
	printf("First 5 elements: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%f ", v[i]);
    }
    printf("\n\n");	
    
    printf("Last 5 elements: ");
    for (int i = n-5; i<n; i++)
    {
        printf("%f ", v[i]);
    }
    printf("\n\n");	
}


void CheckKernels(long long n){
    printf("Test For array size n = %d\n", n);

    float* A = (float*) malloc((size_t)n * n * sizeof(float));
    float* v = (float*)malloc((size_t)n * sizeof(float));
    float* result_c = (float*)malloc((size_t)n * sizeof(float));
    float* result_x86 = (float*)malloc((size_t)n * sizeof(float));
    float* result_xmm = (float*)malloc((size_t)n * sizeof(float));
    float* result_ymm = (float*)malloc((size_t)n * sizeof(float));

    InitializeData(A,v,n);

    printf("Testing C Time... \n");
    double tC = TimeKernel(MultMatrixVector, A, v, result_c,   n);
    printf("Testing x86 Time...\n");
    double tX86 = TimeKernel(x86Scalar, A, v, result_x86, n);
    printf("Testing XMM Time...\n");
    double tXMM = TimeKernel(SIMD_XMM, A, v, result_xmm, n);
    printf("Testing YMM Time...\n");
    double tYMM = TimeKernel(SIMD_YMM, A, v, result_ymm, n);

    printf("C time: %f s\n", tC);
    printf("x86-64 time: %f s\n", tX86);
    printf("XMM SIMD time: %f s\n", tXMM);
    printf("YMM SIMD time: %f s\n\n", tYMM);

    DisplayFirstLast5("C :", result_c, n);
    DisplayFirstLast5("x86-64 :", result_x86, n);
    DisplayFirstLast5("XMM SIMD :", result_xmm, n);
    DisplayFirstLast5("YMM SIMD :", result_ymm, n);

    printf("Compare test: \n");
    printf("C:");
    CompareVectors(result_c, result_c, n);
    printf("\nx86:");
    CompareVectors(result_c, result_x86, n);
    printf("\nXMM SIMD:");
    CompareVectors(result_c, result_xmm, n);
    printf("\nYMM SIMD:");
    CompareVectors(result_c, result_ymm, n);
    printf("\n");


    
    free(A); free(v); free(result_c); free(result_x86); free(result_xmm); free(result_ymm);

}

int main(){
    printf("Data init formula: x[i] = sin(i*0.001); A[i][j] = cos((i*n+j)*0.001)\n");
    printf("Each kernel timed over %d runs, averaged.\n", REPEAT);

    for (int k = 0; k < NUM_TEST_SIZES; k++) {
        CheckKernels(TEST_SIZES[k]);
    }

    printf("\nBOUNDARY TEST : n = %d, not a multiple of 4 or 8\n",
           BOUNDARY_SIZE);
    CheckKernels(BOUNDARY_SIZE);

    return 0;
}