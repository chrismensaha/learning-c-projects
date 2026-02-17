#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define starting_SIZE 100


int word_count(char* sentence){
    enum STATE{OUTWORD, 
                INWORD 
                };

    enum STATE state = OUTWORD;
    int count=0;
    for (int i=0;i<sentence[i]!='\0';i++){
        if (state==INWORD){
            if (sentence[i]==' '){
                state=OUTWORD;
            }
        }
        else if(state==OUTWORD){        
            if (sentence[i]!=' '){
                count++;
                state=INWORD;
            }
        }
}
    return count;
}          
    
int main(){

    char* sentence = calloc(starting_SIZE,sizeof(char));

    printf("Type Your Sentence Here: ");
    fgets(sentence,starting_SIZE,stdin);

    sentence[strcspn(sentence, "\n")] = 0;

    int final_count = word_count(sentence);
    
    printf("%d",final_count);
    free(sentence);
    return 0;

}