#include <stdio.h>
#include <stdlib.h>
#include "calculator.c"

int main(){
    int size=0, count=0;
    double *history=NULL;
    
    while (1){        
        double a=0,b=0,result=0;
        char mode=0;
        
        printf("Enter here:");
        scanf("%lf%c%lf",&a,&mode,&b);    

        result=0;
        switch (mode){
            case '+':result=add(a,b);break;
            case '-':result=subtract(a,b);break;                
            case '*':result=multiply(a,b);break;     
            case '/':
                if (b !=0){
                    result=divide(a,b); 
                }
                else{
                    printf("Error! Division by zero\n");                    
                }               
                break;
            default:
                printf("Invalid\n");
                continue;
            }

        double *temp = realloc(history,(count+1)*sizeof(double));  
        history=temp;
        history[count++]=result;   
        
        printf("= %.2f\n",result);
        printf("History:\n");
        for (int i=0;i<count;i++) { 
                    
            printf("%.2f\n",history[i]);
            } 
                
        
    }
    free(history);
    return 0;
}
