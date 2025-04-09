#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define MIN_VAL -25
#define MAX_VAL 74

int* generate_array(int size, unsigned int seed) {
    srand(seed);
    int* arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % (MAX_VAL - MIN_VAL + 1)) + MIN_VAL;
    }
    return arr;
}
//brute force
int max_subarray_n3(int* arr, int size) {
    int max_sum = INT_MIN;
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }
            if (sum > max_sum) max_sum = sum;
        }
    }
    return max_sum;
}
//better bruteforce
int max_subarray_n2(int* arr, int size) {
    int max_sum = INT_MIN;
    for (int i = 0; i < size; i++) {
        int sum = 0;
        for (int j = i; j < size; j++) {
            sum += arr[j];
            if (sum > max_sum) max_sum = sum;
        }
    }
    return max_sum;
}
//kadanes algorithm
int max_subarray_n(int* arr, int size) {
    int max_sum = arr[0];
    int current_sum = arr[0];
    for (int i = 1; i < size; i++) {
        current_sum = (arr[i] > current_sum + arr[i]) ? arr[i] : current_sum + arr[i];
        if (current_sum > max_sum) max_sum = current_sum;
    }
    return max_sum;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "usage: %s <seed> <size>\n", argv[0]);
        return 1;
    }
    //atoi converts string to integer
    unsigned int seed = atoi(argv[1]);
    int size = atoi(argv[2]);

    clock_t start_gen = clock();
    int* arr = generate_array(size, seed);
    clock_t end_gen = clock();

    clock_t start_n3 = clock();
    int result_n3 = max_subarray_n3(arr, size);
    clock_t end_n3 = clock();

    clock_t start_n2 = clock();
    int result_n2 = max_subarray_n2(arr, size);
    clock_t end_n2 = clock();

    clock_t start_n = clock();
    int result_n = max_subarray_n(arr, size);
    clock_t end_n = clock();

    printf("results:\n");
    printf("O(n^3) max sum: %d\n", result_n3);
    printf("O(n^2) max sum: %d\n", result_n2);
    printf("O(n)   max sum: %d\n", result_n);

    printf("\ntiming (CPU cycles):\n");
    printf("generation: %.2f sec\n", (double)(end_gen - start_gen) / CLOCKS_PER_SEC);
    printf("O(n^3):     %.2f sec\n", (double)(end_n3 - start_n3) / CLOCKS_PER_SEC);
    printf("O(n^2):     %.2f sec\n", (double)(end_n2 - start_n2) / CLOCKS_PER_SEC);
    printf("O(n):       %.2f sec\n", (double)(end_n - start_n) / CLOCKS_PER_SEC);

    free(arr);
    return 0;
}