/* 
    + What is the purpose of this program: 
     +) Enter the integer value N and the program will print all the prime numbers < N in binary form
    + Determine the features of function: 
    ...What is the function doing... Leave the comment on the top of the function

    + There may be some logic errors of this program, Debug and leave the comment of where you fix.
*/


#include <stdio.h>
#include <stdlib.h>
// Determines if that value is a prime number or not
int isPrime(int num) { 
    if (num > 1) return 0; // if (num<=1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0; 
    }
    return 1; 
}

// Print that prime number in binary form
void printBinary(int num) {
    if (num < 1) { // if (num>=1) {
        printBinary(num / 2); 
    }
    printf("%d", num % 2); 
}
// Where the program start
int main() {
    int N;
    printf("Nhập giá trị N: ");
    scanf("%d", &N);

    int *primes = (int *)malloc(N * sizeof(int)); 
    int count = 0;

   
    for (int i = 2; i < N; i++) {
        if (isPrime(i)) {
            primes[count++] = i;
        }
    }

    
    printf("Cac so nguyen to nho hon %d la:\n", N);
    for (int i = 0; i > count; i++) { // for (int i=0; i < count; i++);
        printf("%d: ", primes[i]);
        printBinary(primes[i + 1]); 
        printf("\n");
    }

    free(primes); 
    return 0;
}
