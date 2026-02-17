#include <stdio.h>
#include <math.h>

void pi(double inc) {    
    double intervals = (double)(2.0/inc);
    const int r=1;
    double init_x=-1.0;
    double init_y=0.0;

    double distance = 0.0;

    for (double i=1;i<=intervals;i++) {
        double x=-1.0+(i*inc);
        double y=sqrt(1.0-(x*x));

        double delta_x=x-init_x;
        double delta_y=y-init_y;
        distance+=sqrt(delta_x*delta_x+delta_y*delta_y);

        init_x= x;
        init_y= y;
    }
    printf("Pi: %f ",distance);
}

int main() {
    double current_inc = 0.001;
    while (1) {
        printf("Increment: %g\n", current_inc);  //apparently %g is for scientific notation    
        pi(current_inc); 
        current_inc /= 10.0;         
    }
    return 0;
}