/* 
    + What is the purpose of this program  : 
    Identif Prime Numbers:finds all prime numbers that are less than a integer 
    After identifying the prime numbers, it prints each prime number smaller than the integer and its binary form 
    + Determine the features of function: 
    ...What is the function doing... Leave the comment on the top of the function

    + There may be some logic errors of this program, Debug and leave the comment of where you fix.
*/


#include <stdio.h>
#include <stdlib.h>

//Function to check if a number is prime
int isPrime(int num) 
{
    //Wrong(very first condition of a prime number is greater than 1)
    //if (num > 1) return 0; 
    if(num<=1)
        return 0;
    for (int i = 2; i * i <= num; i++) 
    {
        if (num % i == 0) return 0; 
    }
    return 1; 
}

//Recursive function to print binary form of a number
void printBinary(int num) 
{
    //Wrong(num<1 then there wont be binary form(at least for this function's algorithm))
    //if (num < 1) 
    if(num>1)
    {
        printBinary(num / 2); 
    }
    printf("%d", num % 2); 
}

int main() {
    int N=0;
    printf("Nhap gia tri N: ");
    scanf("%d", &N);

    int *primes = (int *)malloc(N * sizeof(int)); 
    int count = 0;

   
    for (int i = 2; i < N; i++) {
        if (isPrime(i)) {
            primes[count++] = i;
        }
    }

    
    printf("Cac so nguyen to nho hon %d la:\n", N);
    //Basic mistake : i>count
    for (int i = 0; i < count; i++) 
    {
        printf("%d: ", primes[i]);
        //primes[i] is not wrong
        printBinary(primes[i]); 
        printf("\n");
    }

    free(primes); 
    return 0;
}