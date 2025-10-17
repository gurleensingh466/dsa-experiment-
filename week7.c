#include <stdio.h>
#include <string.h>

#define MAX 10

int stack[MAX];
int top = -1;

int pop() {
    if (top == -1) {
        printf("Stack Underflow! Nothing to pop.\n");
        return -1;
    } else {
        int x = stack[top--];
        printf("%d popped from stack.\n", x);
        return x;
    }
}

void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Can't push %d.\n", val);
    } else {
        stack[++top] = val;
        printf("%d pushed onto stack.\n", val);
    }
}

void demonstrateOverflow() {
    printf("Showing what happens when stack overflows:\n");
    top = -1;
    for (int i = 0; i <= MAX; i++)
        push(i);
}

void displayStack() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (top to bottom):\n");
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

void demonstrateUnderflow() {
    printf("Showing what happens when stack underflows:\n");
    top = -1;
    pop();
}

void checkPalindrome() {
    char s[MAX], r[MAX];
    printf("Enter a string to check palindrome: ");
    scanf("%s", s);
    int n = strlen(s);
    top = -1;
    for (int i = 0; i < n; i++)
        push(s[i]);
    for (int i = 0; i < n; i++)
        r[i] = (char)pop();
    r[n] = '\0';
    if (strcmp(s, r) == 0)
        printf("\"%s\" is a palindrome.\n", s);
    else
        printf("\"%s\" is not a palindrome.\n", s);
}

int main() {
    printf("Test push:\n");
    push(10);
    push(20);
    push(30);
    displayStack();

    printf("\nTest pop:\n");
    pop();
    displayStack();

    printf("\nTest palindrome check:\n");
    checkPalindrome();

    printf("\nTest overflow demonstration:\n");
    demonstrateOverflow();

    printf("\nTest underflow demonstration:\n");
    demonstrateUnderflow();

    printf("\nFinal stack status:\n");
    displayStack();
    return 0;
}
