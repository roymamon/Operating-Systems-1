#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

int main(int argc, char *argv[]) {
    if (argc < 3 || argc > 4) {
        fprintf(stderr, "Usage: %s <real> <imag> [max_iterations](optional)\n", argv[0]);
        return 1;
    }
    //atof - converts string (users input) to double
    double real = atof(argv[1]);
    double imag = atof(argv[2]);
    //4 because argv[0] contains the programs name
    int max_iter;
    if (argc == 4) {
        max_iter = atoi(argv[3]);
    } else {
        max_iter = 1000;
    }

    complex double c = real + imag * I;
    complex double z = 0;
    int n = 0;

    while (n < max_iter && cabs(z) <= 2.0) {
        z = z*z + c;
        n++;
    }

    if (cabs(z) <= 2.0) {
        printf("%.3f + %.3fi is in the Mandelbrot set\n", real, imag);
    } else {
        printf("%.3f + %.3fi is not in the Mandelbrot set\n", real, imag);
    }

    return 0;
}
