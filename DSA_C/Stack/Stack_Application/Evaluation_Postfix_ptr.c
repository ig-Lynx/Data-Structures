// lab program 3 9(without pointers)

#include<stdio.h>
#include<ctype.h> // this included to check for isdigit()
#include<stdlib.h>
#include<math.h>
#define MAX 100 
void push(int stack[], int *top, int value);
int pop(int stack[],int *top);
int EvaluatePostfix(char *exp);

int main() {
    char exp[] = "82-34*22^/+";
    printf("Postfix Evaluation : %d", EvaluatePostfix(exp));

    return 0;
}

void push(int stack[], int *top, int value) {
    if (*top == (MAX - 1)) {
        printf("Stack overflow\n");
        return;
    }
    
    stack[++(*top)] = value;
}

int pop(int stack[], int *top ){
    if(*top == -1){
        printf("Stack underflow \n");
        exit(1);
    }
    return stack[(*top)--];
}

int EvaluatePostfix(char *exp){
    int stack[MAX];
    int top = -1;
    int i = 0;

    // scan the characters
    for(i=0;exp[i];i++){

        // if the character is digit then push it into the stack
        if(isdigit(exp[i])){
            push(stack,&top,exp[i]-'0');
        }\
        
        // to skip the blank spaces
        // else if (exp[i] == ' ') {
        //     i++;
        //     continue;
        // }

        // if the character is an Operator then pop two operands and push the result into the stack 
        else {
            int val1 = pop(stack,&top);
            int val2 = pop(stack,&top);
            
            // using swtich to evaluate the expression
            switch(exp[i]){
                case'+' : push(stack,&top,val2+val1);
                    break;
                case'-' : push(stack,&top,val2-val1);
                    break;
                case'*' : push(stack,&top,val2*val1);
                    break;
                case'/' : push(stack,&top,val2/val1);
                    break;
                case'^' : push(stack,&top,pow(val2,val1));
                    break;
                default :
                    printf("Invalid operator \n");
                    exit(1);
            }
        }
    }

    // the result will be in the stack 
    return pop(stack,&top);
}