/**************************************
----Name:Chris-Mensah------------------
----Course:CS222-Systems-Programming---
----File:"primes_array.c"--------------
----Description:Receive-User-Input-----
----Check-If-Prime-Store-If-True-------
**************************************/
#include <stdio.h>
/*
50,000,000 times a type int or long long would be too big for the stack so
made it global to use the data segment
Also figured this would be better than initializing this huge array a
bunch of times
*/
#define MAX_SIZE 50000000
unsigned int array[MAX_SIZE];
unsigned int prime_count=0;
short int is_prime(unsigned long long num) {
    char is_prime=1;
    for (int j=3;(j*j)<=num;j+=2){
        if (num % j==0){
            is_prime=0;
            return 0;
        }
    }
    return 1;
}
void store_primes(){
    unsigned long long input_max;
    printf("Enter your number: ");
    scanf("%llu",&input_max);
    array[0]=2;
    array[1]=3;
    prime_count=2;
    for (unsigned int number=5;number<=input_max;number+=2){
        if (is_prime(number)){
            if (prime_count<MAX_SIZE){
                array[prime_count]=number;
                }
            prime_count++;
            }
        }
    printf("Total primes found: %u\n",prime_count);
}
int main(){
    store_primes();
    return 0;
}