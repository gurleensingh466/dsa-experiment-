#include <stdio.h>
int sum(int n) {
    if (n == 0)
        return 0;
    else
        return n + sum(n - 1);
}
int main() {
    int n;
    printf("Enter a positive number: ");
    scanf("%d", &n);
    printf("Sum of first %d numbers = %d\n", n, sum(n));
    return 0;
}


//code 2
#include <stdio.h>
int fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
    int n, i;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Sequence: ");
    for(i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    return 0;
}
//code 3
#include <stdio.h>
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    
    printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}
int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    printf("The sequence of moves:\n");
    towerOfHanoi(n, 'A', 'C', 'B'); 
    return 0;
}
