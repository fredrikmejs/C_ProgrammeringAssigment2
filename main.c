#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

struct dynamicArray {
    double *array;
    int used;
    int size;
};

int assignment2A(const double arr[]);
int goldbach(double arr[], int length);
void add (struct dynamicArray *arr, double value);
bool equals (double d1, double d2, int precession);
bool hasRightAngle (double a, double b, double c);

/**
 * Main function
 * @return
 */
int main() {
int n = 0;

    struct dynamicArray arr;
    arr.array = malloc(1);
    arr.size = 1;
    arr.used = 0;
    double temp;

    for (int j = 0; j < sizeof(arr); j++) {
        printf("Please enter a number: ");
        scanf("%lf", &temp);
        add(&arr, temp);
        if (arr.array[j] == 0){
            break;
        }
    }

    assignment2A(arr.array);
    goldbach(arr.array, arr.used);
    printf("\n--------------------------\n");
    printf("Enter three sides of a triangle\n");
    double a, b, c;
    scanf("%lf %lf %lf", &a,&b,&c);
    if(hasRightAngle(a,b,c))
        printf("It's right");
    else
        printf("It's not right");


    return 0;
}
/**
 * function to count the number of even and odd number
 * Checks the average of the values
 * @param countedE just a simple name for the counted even numbers -1 because of 0.
 * @param sumAverageEven the total sum of the even numbers
 * @param countOdd the counted odd numbers raied by 1 each time there is an odd number
 * @param sumAverageOdd the sum of the total value of the odd numbers
 * @param arr the array from the main function
 * @return
 */
int assignment2A(const double arr[]){
    int countEven = 0;
    double sumAverageEven;
    int countOdd = 0;
    double sumAverageOdd;
    double sumE = 0;
    double sumO = 0;
    int k = 0;

    while (true) {
        //checks for even numbers
        if ((int) arr[k] % 2 == 0) {
            sumE += arr[k];
            countEven++;
        }
        //checks for odd numbers
        if ((int) arr[k] % 2 != 0) {
            sumO += arr[k];;
            countOdd++;
        }
        //breaks if the element in arr is 0
        if (arr[k] == 0) {
            break;
        }
        k++;
    }
    //finds the average
    int countedE = countEven-1;
    sumAverageEven = sumE/countedE;
    sumAverageOdd = sumO/countOdd;


    printf("The number of even numbers: %d\n", countedE);
    if(countedE > 0){
    printf("The average of the even numbers: %lf\n", sumAverageEven);
    } else printf("The average of the even numbers: %d\n", 0);

    printf("The number of odd numbers: %d\n", countOdd);
    if (countOdd > 0 ) {
        printf("The average of the odd numbers: %lf\n", sumAverageOdd);
    } else printf("The average of the odd numbers: %d\n", 0);
}

/**
 * Checks if the sum of two prime numbers is equal to the element of th arr
 * @param j the index from the goldbach function
 * @param arr the array
 * @return it returns true or false
 */
bool SumOfPrime(int j, const double arr[]) {
    int n = (int) arr[j], fg1, fg2, fg3 = 0,k;
int i = 2;

    while (i <= n / 2) {
        fg1 = 1;
        fg2 = 1;
        for (k = 2; k < i; k++) {

            if (i % k == 0) {
                fg1 = 0;
                k = i;
            }
        }
        for (k = 2; k < n - i; k++) {
            if ((n - i) % k == 0) {
                fg2 = 0;
                k = n - i;
            }
        }
        // it's true if the 2 other conditions are false.
        if (fg1 == 1 && fg2 == 1) {
            return true;
        }
        i++;
    }   //returns true
        if (fg3 == 0) {
            return false;
        }
}




/**
 * function to find the first natural number in the array and print
 * the numbers bellow the first natrual number and makes sure
 * that the sum of to prime numbers are not equal it
 * @param n n is the first natural number in the array
 * @param arr the array
 * @param length the length is the length of the array- 1 because of 0
 * @return
 */
int goldbach(double arr[], int length){
int n;
    for (int i = 0; i < length;) {
        //makes sure the number is a natural number
        if ((int)arr[i]%2 == 0 ||  (int)arr[i]%2 == 1){
             n = arr[i];
            printf("the first natural number: %d\n",n);
            break;
        }
        i++;
    }
    printf("Numbers below %d:",n);
    for (int j = 0; j < length; ) {
        //makes sure the it's a Natural number and it's not the sum of two prime numbers
        if (arr[j] < n && arr[j] > 0 && !SumOfPrime(j, arr)){
            int q = arr[j];
            printf(" %d",q);
        }
            j++;
    }
}


bool hasRightAngle (double a, double b, double c) {
    double hyp = 0, adjacent1 = 0, adjacent2 = 0;

    if(a > b && a > c){
    hyp = a;
    adjacent1 = c;
    adjacent2 = b;
    } else if(b > a && b > c){
        hyp = b;
        adjacent1 = a;
        adjacent2 = c;
    } else if (c > a && c > b){
        hyp = c;
        adjacent1 = a;
        adjacent2 = b;
    } else if(a == c && a == b){
        return false;
    }

    double powA1 = pow(adjacent1,2), powA2 = pow(adjacent2,2), powHyp =pow(hyp,2);
    double sumOfPow =powA1 + powA2;
   if(equals(sumOfPow,powHyp,2) ){
       return true;
   }

    return false;
}

bool equals (double d1, double d2, int precession) {
    if (d1 == d2)
        return true;
    if (d1 > d2)
        return d1 - d2 < (double) 1 / precession;
    else
        return d2 - d1 < (double) 1 / precession;
}

void add (struct dynamicArray *arr, double value) {
    if (arr->size == arr->used) {
        arr->size *= 2;
        arr->array = (double *) realloc(arr->array, arr->size * sizeof(double));
    }

    arr->array[arr->used++] = value;
}