#include <stdio.h>
#include <math.h>

#ifndef M_PI
# define M_PI		3.14159265358979323846	/* pi */
#endif

/*
 * Return a Gaussian modulated sinusoid:
 *     ``exp(-a t^2) exp(1j*2*pi*fc*t).``
 */
int gaussian_pulse(float *t, float *real, int len, float fc, float bw, float bwr) {
    if (fc < 0) {
        fprintf(stderr, "Center frequency must be >= 0\n");
        return -1; 
    } 
    if ( bw <= 0 ) {
        fprintf(stderr, "Franctional bandwidth must be > 0\n");
        return -1; 
    } 
    if (bwr >= 0 ) {
        fprintf(stderr, "Reference level for bandwidth must be < 0 db\n");
        return -1; 
    }

    float ref = pow(10.0, bwr / 20.0);
    float a = -pow((M_PI * fc * bw), 2) / (4.0 * log(ref));
    float yenv;

    for (int i = 0; i < len; i++) {
        yenv = exp(-a * t[i] * t[i]);
        real[i] = yenv * cos(2.0 * M_PI * fc * t[i]);
    }

    return 1;
}
