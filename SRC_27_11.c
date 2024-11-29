/* 
    + What is the purpose of this program: 
    -> Chức năng của chương trình này là in ra các chữ số nguyên tố nhỏ hơn N và biểu diễn chúng dưới dạng nhị phân
    + Determine the features of function: 
    ...What is the function doing... Leave the comment on the top of the function

    + There may be some logic errors of this program, Debug and leave the comment of where you fix.
*/


#include <stdio.h>
#include <stdlib.h>

// Hàm kiểm tra số nguyên tố
int isPrime(int num) {
    //if (num > 1) return 0; sai điều kiện kiểm tra số nguyên tố, sửa thành:
    if(num <=1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0; 
    }
    return 1; 
}

// hàm in ra số nguyên dưới dạng nhị phân
void printBinary(int num) {
    if (num > 1) //lỗi điều kiện dừng đệ quy, sửa thành num > 1
    {
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
    for (int i = 0; i < count; i++) // sai điều kiện vòng lặp, sửa thành i <=20 count
    {
        printf("%d: ", primes[i]);
        printBinary(primes[i]); // sửa thành printBinary(primes[i]);
        printf("\n");
    }

    free(primes); 
    return 0;
}