#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact_book.c"

/*
* Main program for contact book management
* Ability to add, list, and delete contacts
* Utilizes dynamic memory allocation for storage flexibility
*/

int main(){
    // mode: menu selection
    // input_number: number of contacts to add
    // size: max length for input strings
    // contactsize: current number of contacts stored
    // starting_num: initial number of contacts allocated
    int mode=0, input_number=0, size=100, contactsize=0, starting_num=10;
    int c, user_exit;
    Contact *contact; // Pointer to Contact structs array
    
    // Initial memory allocation for contacts
    contact=calloc(starting_num,sizeof(Contact));

    // Main loop for continuous input requests
    while (1){
        printf("Press [1] to Add a contact, [2] to List all contacts, or [3] to Delete a contact: ");
        scanf("%d",&mode);
        switch (mode)
        {
        case 1: // Add contacts
            printf("# of contacts to add: ");        
            scanf("%d",&input_number);

            // Validate Input
            if (input_number<=0){
                printf("INVALID INPUT! Try Again\n"); break;}
            else {  
                // Reallocate memory for new contacts              
                Contact *temp=realloc(contact,(contactsize+input_number)*sizeof(Contact));
                if (!temp) {
                    printf("Error! Memory allocation failed\n");
                    break;
                    }
                contact=temp;

                int start_index = contactsize;
                contactsize+=input_number;
                
                // Clear leftover newline
                while ((c = getchar()) != '\n' && c != EOF); 
                
                // Loop to fill new contact entries
                for(int i=start_index; i<start_index+input_number;i++){
                    contact[i].name=malloc(size*sizeof(char));
                    contact[i].number=malloc(size*sizeof(char));

                    printf("Enter name: ");             
                    fgets(contact[i].name,size,stdin);  
                    contact[i].name[strcspn(contact[i].name, "\n")] = '\0';  

                    printf("Enter number: ");        
                    fgets(contact[i].number,size,stdin);            
                    contact[i].number[strcspn(contact[i].number, "\n")] = '\0';

                    printf("You have entered: Index [%d] {%s, %s}\n",i, contact[i].name, contact[i].number);              

                    }
                }        
        
        break;        
        case 2: // List all contacts
                if (contactsize==0){ printf("Empty contactbook! Please add a contact first\n"); break;}
                else{ 
                    for(int i=0;i<contactsize;i++){ 
                        printf("Index [%d] | {%s, %s}\n",i, contact[i].name, contact[i].number);}                                                                            
                    } break;
        case 3: // Delete a contact
                if (contactsize!=0){
                    int del_index;
                    printf("Enter the index you would like to delete: ");
                    scanf("%d",&del_index); 

                    // Validate index
                    if (del_index < 0 || del_index >= contactsize) {
                        printf("Invalid Input!\n");
                        break;}

                    // Free memory of the deleted contact
                    free(contact[del_index].name);
                    free(contact[del_index].number);
                    
                    // Shift remaining contacts down by one
                    for (int i=del_index; i<contactsize-1;i++){
                        contact[i]=contact[i+1];
                    }
                        
                    contactsize--;

                    Contact *temp2 = realloc(contact, contactsize * sizeof(Contact));
                    if (!temp2 | contactsize==0) {
                        printf("Error! Memory allocation failed\n");
                        contact=temp2;
                        }

                    printf("Contact deleted.\n");
                    

                    } else { 
                    printf("Error! Add a contact first\n");                                     
                } 
                break;
        default:
            break;
        }

        // Ask if the user wants to continue or exit
        printf("Press [1] to continue | Press [0] to exit: ");
        scanf("%d",&user_exit);

        if (user_exit==0){ 
            // Free all allocated memory before exit
            for(int i=0;i<contactsize;i++){
                free(contact[i].name);
                free(contact[i].number);}
        break;}
        else continue;
        }
    // Free main array
    free(contact);
    return 0;
}