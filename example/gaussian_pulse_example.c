#include <stdio.h>
#include <stdlib.h>
#include "../src/gaussian_pulse.h"

int main() {
    #define LEN 200
    float t[LEN], real[LEN];
    for (int i = -100; i < LEN/2; i++) {
        t[i+100] = (float)i/100;
    }

    gaussian_pulse(t, real, LEN, 5, 0.5, -6);
    FILE *f = fopen("gauss_pulse.csv", "w");

    for (int i = 0; i < LEN; i++) {
        fprintf(f, "%f,%lf\n", t[i], real[i]);
    }
    
    fclose(f);

    return 0;
}

