#include "password-checker.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    size_t size_buffer=STARTING_SIZE;
    char* file_name=malloc(size_buffer*sizeof(char));
    printf("Enter file name here: ");
    fgets(file_name,STARTING_SIZE,stdin);
    file_name[strcspn(file_name, "\n")] = 0;

    check_password();

    Password password;
    char* str=malloc(STARTING_SIZE*sizeof(char));
    FILE *file = fopen(file_name,"r");   
    FILE *file_ptr = fopen("filtered_file.txt","w");

    if (file==NULL){
        printf("Error Opening File!\n");
        free(str);
        
        free(file_name);
        return 1;
    }

    if (file_ptr==NULL){
        fclose(file);
        printf("Error Opening File!\n");
        free(str);
        
        free(file_name);
        return 1;
    }

    while (fgets(str, STARTING_SIZE, file) != NULL){       
        str[strcspn(str, "\n")] = 0;
        password_checker(str,&password);
        if (password.has_num && password.has_upper && password.is_secure_length){
            fprintf(file_ptr,"%s\n",str);
        }
    }

    fclose(file_ptr);
    fclose(file);
    free(str);
    
    free(file_name);
    return 0;

}