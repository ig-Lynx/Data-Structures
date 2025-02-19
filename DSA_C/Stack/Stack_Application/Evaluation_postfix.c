// Lab program 3 ( without pointers )

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int EvaluatePostfix(char exp[]) {
    int i;
    for (i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else if (exp[i] == ' ') {
            continue;
        } else {
            int val1 = pop();
            int val2 = pop();
            switch (exp[i]) {
                case '+':
                    push(val2 + val1);
                    break;
                case '-':
                    push(val2 - val1);
                    break;
                case '*':
                    push(val2 * val1);
                    break;
                case '/':
                    push(val2 / val1);
                    break;
                case'^' : push(pow(val2,val1));
                    break;
                default:
                    printf("Invalid character: %c\n", exp[i]);
                    exit(1);
            }
        }
    }
    return pop();
}



int main() {
    char exp[] = "82-34*22^/+";
    printf("Postfix Evaluation : %d", EvaluatePostfix(exp));

    return 0;
}

// int main() {
//     char exp[MAX];
//     printf("Enter the postfix expression: ");
//     fgets(exp, MAX, stdin);
//     printf("Result: %d\n", EvaluatePostfix(exp));
//     return 0;
// }