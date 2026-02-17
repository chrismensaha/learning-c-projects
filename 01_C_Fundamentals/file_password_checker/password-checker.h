#ifndef PASSWORD_CHECKER_H
#define PASSWORD_CHECKER_H
#define STARTING_SIZE 100 


typedef struct password
{
    int is_secure_length;
    int has_num;
    int has_upper;
} Password;

void password_checker(char* input, Password* result);
void check_password();

#endif