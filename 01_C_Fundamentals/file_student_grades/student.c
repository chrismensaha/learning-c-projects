/*Write the student names and grades to a file (e.g., Students.txt).
Close and reopen the file for reading.
Ask the user for a name to find.
Loop through the file. 
If you find a match, print their grade and whether they passed (Grade $\ge$ 60).
If you get to the end of the file and haven't found them, print "Student not found."*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STARTING_SIZE 100

typedef struct student{
    char* name;
    double grade;
}Student;

int main(){
    Student student;
    
    char* filename=malloc(STARTING_SIZE*sizeof(char));  
    char* fileline=malloc(STARTING_SIZE*sizeof(char)); 
    char* name=malloc(STARTING_SIZE*sizeof(char));
    
    student.name=name;

    printf("Enter File Name: ");
    fgets(filename,STARTING_SIZE,stdin);  
        filename[strcspn(filename, "\n")] = 0;
    printf("Enter Student Name: ");  
    fgets(name,STARTING_SIZE,stdin);
        name[strcspn(name, "\n")] = 0;
    printf("Enter Student Grade: "); 
    scanf("%lf",&student.grade);
        while (getchar() != '\n');


    FILE* file = fopen(filename,"w");

    if (file==NULL){
        free(filename);
        free(name);
        return 1;
    }

    fprintf(file,"%s ",student.name);
    fprintf(file,"%.1f\n",student.grade); 

    fclose(file);
    FILE* fileptr = fopen(filename,"r");

    if (fileptr==NULL){
        free(filename);
        free(name);
        return 1;
    }

    double temp_grade=0.0;
    char has_passed=0;
    int passed=0;
    int total=0;
    char isfound=1;
    char* temp_name=malloc(STARTING_SIZE*sizeof(char));

    while(fgets(fileline,STARTING_SIZE,fileptr)!=NULL){
        fileline[strcspn(fileline, "\n")] = 0;       
        if (sscanf(fileline, "%[^ ] %lf", temp_name, &temp_grade) == 2){
            if (strcmp(temp_name,name)==0){
                if (temp_grade>=60.0){
                    printf("Student: %s Grade: %.1f\n",temp_name,temp_grade); 
                    passed++;
                }
                else {
                    printf("Student is failing\n"); 

                }
            total++;
            }
            else{
                isfound=0;
                printf("Student %s Not Found!\n",temp_name);
            }
        }
        printf("%d of %d Students Passed",passed,total);
    }

    free(name); 
    free(filename);
    free(temp_name);
    fclose(fileptr);
    return 0;

}