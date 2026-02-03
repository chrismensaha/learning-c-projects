#include <stdio.h>
#include <stdlib.h>
#define STARTING_SIZE 100

typedef struct expense{
    char* item_name;
    double price;
} Expense;

int main(){
    Expense* expense=malloc(sizeof(Expense));
    char* item_name=malloc(STARTING_SIZE*sizeof(char));
    expense->item_name=item_name;
    char* file_name=malloc(STARTING_SIZE*sizeof(char));
    printf("File Name: ");
    fgets(file_name,STARTING_SIZE,stdin);
    file_name[strcspn(file_name, "\n")]=0; 

    char* file_line=malloc(STARTING_SIZE*sizeof(char));
    FILE* file=fopen(file_name,"w");

    if (file==NULL){
        free(expense);
        free(file_line);
        free(file_name);
        free(item_name);
        return 1;
    }

    int item_number=0;
    printf("# of Items to Store: ");
    scanf("%d",&item_number);
    while (getchar() != '\n');

    for (int i=0;i<item_number;i++){
        printf("Enter Item Name: ");
        fgets(expense->item_name,STARTING_SIZE,stdin);
        expense->item_name[strcspn(expense->item_name, "\n")] = 0;

        printf("Enter Item Price: ");
        scanf("%lf",&expense->price);
        while (getchar() != '\n');

        fprintf(file,"%s: ",expense->item_name);
        fprintf(file,"$%.2f\n",expense->price);

        }
    fclose(file);
    FILE* file_ptr=fopen(file_name,"r");
    if (file_ptr==NULL){
        free(expense);
        free(file_line);
        free(file_name);
        free(item_name);
        return 1;
    }
   
    double total_cost=0.0;
    double temp_price=0.0;

    
    while(fgets(file_line,STARTING_SIZE,file_ptr)!=NULL){
        char* temp_name=malloc(STARTING_SIZE*sizeof(char));
        file_line[strcspn(file_line, "\n")]=0;
        if (sscanf(file_line, "%[^:]: $%lf", temp_name, &temp_price) == 2) { 
            printf("%s: $%.2f\n",temp_name,temp_price);  
            total_cost += temp_price;
        }             
        free(temp_name);         
    }
    printf("$%.2f\n",total_cost);


    fclose(file_ptr);
    free(expense);
    free(item_name);
    free(file_line);
    free(file_name);
    return 0;

}