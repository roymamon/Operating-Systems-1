#include <stdio.h>
#include <complex.h>
#include "mandelbrot.h"

int main() {
    double real, imag;

    while (1) {
        printf("Enter a complex number (real imag): ");
        scanf("%lf %lf", &real, &imag);

        if (real == 0.0 && imag == 0.0) {
            break;
        }

        complex double c = real + imag * I;

        if (is_in_mandelbrot(c, 1000)) {
            printf("%.3f + %.3fi is in the Mandelbrot set\n", real, imag);
        } else {
            printf("%.3f + %.3fi is not in the Mandelbrot set\n", real, imag);
        }
    }

    return 0;
}
