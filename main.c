#include <stdio.h>
#include <stdbool.h>

assignment2A(int countedE, double sumAverageEven, int countOdd, double sumAverageOdd, const double arr[]);
goldbach(int n, double arr[], int length);

int main() {
int countedE = 0, sumAverageEven = 0, countOdd = 0, sumAverageOdd = 0, length = -1, n = 0;
    double arr[100000];
    for (int j = 0; j < sizeof(arr); j++) {
        printf("Please enter a number: ");
        scanf("%lf", &arr[j]);
        length++;
        if (arr[j] == 0){
            break;
        }
    }

    assignment2A(countedE,sumAverageEven,countOdd, sumAverageOdd, arr);
    goldbach(n,arr, length);

    return 0;
}
int assignment2A(int countedE, double sumAverageEven, int countOdd, double sumAverageOdd, const double arr[]){
    int countEven = 0;
    double sumE = 0;
    double sumO = 0;
    int k = 0;

    while (true) {
        if ((int) arr[k] % 2 == 0) {
            sumE += arr[k];
            countEven++;
        }
        if ((int) arr[k] % 2 != 0) {
            sumO += arr[k];;
            countOdd++;
        }
        if (arr[k] == 0) {
            break;
        }
        k++;
    }
    countedE = countEven-1;
    sumAverageEven = sumE/countedE;
    sumAverageOdd = sumO/countOdd;


    printf("The number of even numbers: %d\n", countedE);
    printf("The average of the even numbers: %lf\n", sumAverageEven);
    printf("The number of odd numbers: %d\n", countOdd);
    printf("The average of the odd numbers: %lf\n", sumAverageOdd);
}

bool SumOfPrime(int j, const double arr[]) {
    int n = (int) arr[j], flag1, flag2, flag3 = 0,k;
int i = 2;
    while (i <= n / 2) {
        flag1 = 1;
        flag2 = 1;
        for (k = 2; k < i; k++) {
            if (i % k == 0) {
                flag1 = 0;
                k = i;
            }
        }
        for (k = 2; k < n - i; k++) {
            if ((n - i) % k == 0) {
                flag2 = 0;
                k = n - i;
            }
        }
        if (flag1 == 1 && flag2 == 1) {
            return true;
        }
        i++;
    }
        if (flag3 == 0) {
            return false;
        }
}





int goldbach(int n, double arr[], int length){

    for (int i = 0; i < length;) {
        if ((int)arr[i]%2 == 0 ||  (int)arr[i]%2 == 1){
             n = arr[i];
            printf("the first natural number: %d\n",n);
            break;
        }
        i++;
    }

    printf("Numbers below %d:",n);
    for (int j = 0; j < length; ) {
        if (arr[j] < n && arr[j] > 0 && !SumOfPrime(j, arr)){
            int q = arr[j];
            printf(" %d",q);
        }
            j++;

    }

}

