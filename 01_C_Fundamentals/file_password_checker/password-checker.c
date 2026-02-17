#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "password-checker.h"



void password_checker(char* input, Password* result){
    result->is_secure_length=0;
    result->has_num=0;
    result->has_upper=0;
    if (strlen(input)>=8){
        result->is_secure_length=1;
    }
    for (int i=0;input[i]!='\0';i++){
        if (input[i]>='0' && input[i]<='9'){ 
            result->has_num=1;
        }
        if (input[i]>='A' && input[i]<='Z'){ 
            result->has_upper=1;
        }
    }
    }


void check_password(){
    size_t size_buffer = STARTING_SIZE;
    char input[size_buffer];
    char resume='Y';
    
    int is_running=1;
    Password password;
    enum state {A,B};   
    enum state change=A;
    while (is_running){
        switch (change){
        case A:
            printf("Enter password to check: "); 
            fgets(input, sizeof(input), stdin); 
            input[strcspn(input, "\n")] = 0;           
            password_checker(input,&password);
            if (password.is_secure_length==0){printf("Please use a longer password!\n");}
            if (password.has_num==0){printf("Please Include a Number!\n");}
            if (password.has_upper==0){printf("Please Include a Capital Letter!\n");}
            if (password.is_secure_length && password.has_num && password.has_upper){
                printf("That is a strong password!\n"); 
            }
            printf("Press a key to continue | Press N or n to end: ");
            scanf(" %c",&resume);
            while (( getchar()) != '\n');
            if (resume=='N' || resume=='n'){
                change=1;
            } 
            break;
        case B:
            is_running=0;
            break;
            
        default:
            break;
        }
    }
 
}