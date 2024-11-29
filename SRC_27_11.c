 /*   + What is the purpose of this program: 
    nhap n so nguyen, tim va liet ke cac so nguyen to nho hon n và in ra bieu dien nhi phan cua no 
    + Determine the features of function: 
    ...What is the function doing... Leave the comment on the top of the function

    + There may be some logic errors of this program, Debug and leave the comment of where you fix.
*/


#include <stdio.h>
#include <stdlib.h>

int isPrime(int num) { // ham nay xem mot so num co phai so nguyen to khong 
    if (num > 1) return 0; // Loi: num <=1 
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0; 
    }
    return 1; 
}


void printBinary(int num) { // ham nay dung de quy de in ra bieu dien nhi phan cua so nguyen num 
    if (num < 1) { // loi: num > 0 
        printBinary(num / 2); 
    }
    printf("%d", num % 2); 
}

int main() {
    int N;
    printf("Nháº­p giĂ¡ trá»‹ N: ");
    scanf("%d", &N);

    int *primes = (int *)malloc(N * sizeof(int)); 
    int count = 0;

   
    for (int i = 2; i < N; i++) {
        if (isPrime(i)) {
            primes[count++] = i;
        }
    }

    
    printf("Cac so nguyen to nho hon %d la:\n", N);
    for (int i = 0; i > count; i++) {  // loi: i < count 
        printf("%d: ", primes[i]);
        printBinary(primes[i + 1]);    // loi: primes[i] 
        printf("\n");
    }

    free(primes); 
    return 0;
}
