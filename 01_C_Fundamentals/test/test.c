/**************************************
---Name:Chris-Mensah-------------------
---Course:CS222-Systems-Programming----
---File:"pi_float.c"-------------------
---Description:Calculate-Pi-Through----
---Circumference-of-a-Circle-----------
---Increment-X-&-Divide-Increment-by-10
**************************************/
#include <stdio.h>
#include <math.h>
   
int main() {     
    const int r=1;
    float inc=0.001;
    float intervals = (float)(2.0/inc);
    
    float init_x=-1.0;
    float init_y=0.0;
    float distance=0.0;  

    while(init_x<r){
        float x=init_x+inc;
        float inner_value=(r*r)-(x*x);
        if (inner_value<0){
            inner_value=0;
        }
        float y=sqrt(inner_value);

        float delta_x=x-init_x;
        float delta_y=y-init_y;
        distance+=sqrt(delta_x*delta_x+delta_y*delta_y);

        init_x=x;
        init_y=y;       
    }
    printf("Increment: %f | Pi(float): %f\n",inc,distance);

    return 0;
}


