#include <stdio.h>
#include <math.h>
#include <windows.h>

float fx(float x){
    return 60.0*tan(x)
           - 23.184/(cos(x)*cos(x))
           - 0.5;
}

float f_prime(float x){
    return 60.0/(cos(x)*cos(x))
           - 46.368*tan(x)/(cos(x)*cos(x));
}

float x_g = 30.0 * 3.141592653589793 / 180.0;
float x_b = 0.0;
float x_a = 10.0;

int main(){

    int i = 1;

    while(x_a > 0.001){

        printf("Iterasi %d\n", i);
        printf("f(x_g) = %f\n", fx(x_g));
        printf("f'(x_g) = %f\n", f_prime(x_g));

        // simpan x lama
        x_b = x_g;

        // Newton-Raphson
        x_g = x_g - fx(x_g)/f_prime(x_g);

        // hitung error
        x_a = fabs(x_g - x_b);

        printf("x_b = %f\n", x_b);
        printf("x_g = %f\n", x_g);
        printf("error = %f\n\n", x_a);

        i++;

        Sleep(100);
    }

    printf("Akar = %f derajat\n", x_g * 180.0 / 3.141592653589793);

    return 0;
}