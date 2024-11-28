/* 
    + What is the purpose of this program: 
    FIND PRIMES AND ITS BINARY FORM
    + Determine the features of function: 
    YES< SIR

    + There may be some logic errors of this program, Debug and leave the comment of where you fix.
*/


#include <stdio.h>
#include <stdlib.h>
//HAM XAC DINH 1 PRIME
int isPrime(int num) {
    // if (num > 1) return 0; 
    if (num <= 1) return 0; //nhung so nho hon 2 khong phai prime
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0; 
    }
    return 1; 
}

//HAM CONVERT DECIMAL INTO BINARY
void printBinary(int num) {
    if (num > 1) {// ">" was used instead of "<" as we are examining positive numbers that are higher than 1
        printBinary(num / 2); 
    }
    printf("%d", num % 2); 
}

int main() {
    int N;
    printf("Nhập giá trị N: ");
    scanf("%d", &N);

    int *primes = (int *)malloc(N * sizeof(int)); 
    int count = 0;

   //DEM SO PRIMES
    for (int i = 2; i < N; i++) {
        if (isPrime(i)) {
            primes[count++] = i;
        }
    }

    
    printf("Cac so nguyen to nho hon %d la:\n", N);
    for (int i = 0; i < count; i++) {///"<" was used instead of ">" as "count" describes number of primes
        printf("%d: ", primes[i]);
        // printBinary(primes[i + 1]); 
        printBinary(primes[i]);// print binaries, next to decimals
        printf("\n");
    }

    free(primes); 
    return 0;
}
