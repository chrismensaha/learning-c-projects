#include <stdio.h>
#include <math.h>

void pi(float inc) {    
    float intervals = (float)(2.0/inc);
    const int r=1;
    float init_x=-1.0;
    float init_y=0.0;

    float distance = 0.0;

    for (long long i=1;i<=intervals;i++) {
        float x=-1.0+(i*inc);
        double y=sqrt(1.0-(x*x));

        float delta_x=x-init_x;
        float delta_y=y-init_y;
        distance+=sqrt(delta_x*delta_x+delta_y*delta_y);

        init_x= x;
        init_y= y;
    }
    printf("Pi: %f ",distance);
}

int main() {
    float current_inc = 0.001;
    while (1) {
        printf("Increment: %g\n", current_inc);  //apparently %g is for scientific notation    
        pi(current_inc); 
        current_inc /= 10.0;         
    }
    return 0;
}