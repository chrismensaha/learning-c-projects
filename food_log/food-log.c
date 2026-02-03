#include <stdio.h>
/*A New Struct: Create a struct Expense that holds:

A char array for the item name (e.g., "Coffee").

A double for the price.

The Logic Loop: Ask the user how many items they want to log. 
Use a loop to fprintf each item into a file named expenses.txt.

The Calculation Phase: Open that file back up, read it line-by-line
using fscanf or fgets, and keep a running total of the costs.*/

#define STARTING_SIZE 100

typedef struct expense{
    char* item_name;
    double price;
} Expense;

int main(){
    Expense* expense=malloc(sizeof(Expense));
    char* file_name=malloc(STARTING_SIZE*sizeof(char));
    char* file_line=malloc(STARTING_SIZE*sizeof(char));
    FILE* file=fopen("expenses.txt","w");

    if (file==NULL){
        free(expense);
        free(file_line);
    }

    int item_number=0;
    printf("# of Items to Store: ");
    scanf("%d",&item_number);

    for (int i=0;i<=item_number;i++){
        printf("Enter Item Name: ");
        fgets(expense->item_name,STARTING_SIZE,stdin);
        file_line[strcspn(file_line, "\n")] = 0;

        printf("Enter Item Price: ");
        scanf("%.2f",&expense->price);

        fprintf(file,"%s: ",expense->item_name);
        fprintf(file,"$%.2f\n",expense->price);

        }
    fclose(file);
    FILE* file=fopen("expenses.txt","r");
    if (file==NULL){
        free(expense);
        free(file_line);
    }
    
    while(fgets(file_line,STARTING_SIZE,file)!=NULL){
        file_line[strcspn(file_line, "\n")]=0;
        fprintf(file,"%s\n",file_line);
    }

   
    fclose(file);
    free(expense);
    free(file_line);

    return 0;

}