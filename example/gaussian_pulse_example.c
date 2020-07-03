#include <stdio.h>
#include <stdlib.h>
#include "../src/gaussian_pulse.h"

int main() {
    #define LEN 500
    float t[LEN], real[LEN];
    for (int i = -LEN/2; i < LEN/2; i++) {
        t[i+LEN/2] = (float)i/(LEN/2);
    }

    gaussian_pulse(t, real, LEN, 5, 0.4, -6);
    FILE *f = fopen("gauss_pulse.csv", "w");

    for (int i = 0; i < LEN; i++) {
        fprintf(f, "%f,%lf\n", t[i], real[i]);
    }
    
    fclose(f);

    return 0;
}

