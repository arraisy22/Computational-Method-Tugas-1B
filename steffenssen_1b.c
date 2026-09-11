#include <stdio.h>
#include <math.h>

float fx(float x){
    return 60.0*tan(x)
           - 23.184/(cos(x)*cos(x))
           - 0.5;
}


int main(){
    float x_g = 24.0 * 3.141592653589793 / 180.0;
    float x_a;
    float error = 1.0;
    float tol = 0.001;
    int i = 1;

    while(error > tol){
        float f_val = fx(x_g);
        float f_shift = fx(x_g+f_val);
        float denom = f_shift - f_val;
        if (fabs(denom) < 1e-7) {
            printf("Denominator too small, stopping iteration.\n");
            break;
        }
        
        x_a = x_g -(pow(f_val,2)/denom);
        error = fabs(x_a - x_g);
        printf("Iteration %d: x_g = %f, f(x_g) = %f, error = %f\n", i, x_g * 180.0 / 3.141592653589793, f_val, error);
        x_g = x_a;
        i++;
    }
    printf("Akar = %f derajat\n", x_g * 180.0 / 3.141592653589793);
 return 0;
}
