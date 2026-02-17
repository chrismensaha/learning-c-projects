/**************************************
----Name:Chris-Mensah------------------
----Course:CS222-Systems-Programming---
----File:"primes-trial-division.c"-----
----Description:Count-all-the-prime----
----numbers-from-2-to-1,000,000-------
**************************************/

#include <stdio.h>

int main(){
    int count=1;

    for (int i=3;i<1000000;i+=2){
        char is_prime=1;
        for (int j=3; (j*j)<=i;j+=2){
            if (i%j==0){
                is_prime=0;
                break;
            }
        }
        if (is_prime){
            count++;
        }     
    }
    printf("Prime count: %d",count);
    return 0;
}  