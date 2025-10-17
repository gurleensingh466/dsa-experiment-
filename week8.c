#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Oops! Stack is full. Can't push '%c'.\n", c);
    } else {
        stack[++top] = c;
    }
}

char pop() {
    if (top == -1) {
        return '\0';
    } else {
        return stack[top--];
    }
}

char peek() {
    if (top == -1)
        return '\0';
    else
        return stack[top];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}

int precedence(char c) {
    switch (c) {
        case '^': return 3;
        case '*':
        case '/':
        case '%': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int isRightAssociative(char c) {
    return (c == '^');
}

void infixToPostfix(char *infix, char *postfix) {
    int i, j = 0;
    char c, topOp;
    top = -1;

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        if (c == ' ' || c == '\t')
            continue;

        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while ((topOp = pop()) != '\0' && topOp != '(')
                postfix[j++] = topOp;

            if (topOp != '(') {
                printf("Uh-oh! Mismatched parentheses detected.\n");
                postfix[0] = '\0';
                return;
            }
        } else if (isOperator(c)) {
            while (top != -1 && isOperator(peek())) {
                topOp = peek();
                int topPrec = precedence(topOp);
                int currPrec = precedence(c);
                int shouldPop = (isRightAssociative(c)) ? (topPrec > currPrec) : (topPrec >= currPrec);

                if (shouldPop)
                    postfix[j++] = pop();
                else
                    break;
            }
            push(c);
        } else {
            printf("Oops! Invalid character '%c' found in the expression.\n", c);
            postfix[0] = '\0';
            return;
        }
    }

    while ((topOp = pop()) != '\0') {
        if (topOp == '(') {
            printf("Uh-oh! Mismatched parentheses detected.\n");
            postfix[0] = '\0';
            return;
        }
        postfix[j++] = topOp;
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter your infix expression below.\n");
    printf("You can use alphanumeric operands and operators (+, -, *, /, %%, ^).\n");
    printf("Don't forget to use parentheses if needed!\n\n");
    printf("Enter your expression: ");

    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = 0;

    infixToPostfix(infix, postfix);

    if (postfix[0] != '\0')
        printf("\nGreat! Here's the postfix expression:\n%s\n", postfix);
    else
        printf("\nSorry, could not convert the expression due to errors.\n");

    return 0;
}
