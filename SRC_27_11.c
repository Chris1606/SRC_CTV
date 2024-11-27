/* 
    + What is the purpose of this program: 
    Chương trình tìm các số thập phân nhỏ hơn số N nhập từ bàn phím và in ra dạng nhị phân các số đó.
    + Determine the features of function: 
    ...What is the function doing... Leave the comment on the top of the function

    + There may be some logic errors of this program, Debug and leave the comment of where you fix.
*/


#include <stdio.h>
#include <stdlib.h>

// Hàm xác định số nhập vào có phải số nguyên tố không? (trả về 0 nếu không phải, trả về 1 nếu là số nguyên tố)
int isPrime(int num) {
    if (num <= 1) return 0;// Số nguyên tố là số tự nhiên lớn hơn 1
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0; 
    }
    return 1; 
}

// Hàm đệ quy chuyển từ số hệ 10 sang hệ nhị phân
void printBinary(int num) {
    if (num > 1) {// Base case là num bằng 1 hoặc 0
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

   
    for (int i = 2; i < N; i++) {
        if (isPrime(i)) {
            primes[count++] = i;
        }
    }

    
    printf("Cac so nguyen to nho hon %d la:\n", N);
    for (int i = 0; i < count; i++) {//Điều kiện dừng i nhỏ hơn đếm
        printf("%d: ", primes[i]);
        printBinary(primes[i]); //In ra dạng nhị phân của số đó
        printf("\n");
    }

    free(primes); 
    return 0;
}