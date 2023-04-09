#include <stdio.h> 
#include <stdlib.h>
#include "input.h"

void doubleNum(int *val);
void swap(int *a, int *b);
bool arrayMean(int arr[], int arrLength, double *mean);
bool arrayStats(int arr[], int arrLength, int *min, int *max, double *mean);

int main() {

// Ponteiros e passagem de argumentos - 1

    int val = 16;
    int *ptrVal = &val;

    doubleNum(ptrVal);
    printf("Double of val: %d\n", val);

// Ponteiros e passagem de argumentos - 2
    int a = 1;
    int b = 2;

    int *ptrA = &a;
    int *ptrB = &b;
    swap(ptrA,ptrB);

    printf("Value in [a]: %d\n", a);
    printf("Valor em [b]: %d\n", b);

// Ponteiros e passagem de argumentos - 3
 int arr[] = {2,3,4};
 int arrLength = 3;
 double mean = 0;
 double *ptrMean = &mean;

 int meanValue = arrayMean(arr, arrLength, ptrMean);
 printf("Check return arrayMean: %d\n", meanValue);
 printf("Mean result: %.2f\n", mean);

 // Ponteiros e passagem de argumentos - 4

int max, min;
int *ptrMax = &max;
int *ptrMin = &min;
int statsValue = arrayStats(arr, arrLength, ptrMin, ptrMax, ptrMean);
printf("Check return arrayStats: %d\n", statsValue);
printf("Min value: %d\n", min);
printf("Max value: %d\n", max);
printf("Max value: %.2f\n", mean);

//printf("Address of max: %p\n", ptrMax);

    return EXIT_SUCCESS;
}

// Ponteiros e passagem de argumentos - 1

 void doubleNum(int *val){
    *val *= 2;
 }

 // Ponteiros e passagem de argumentos - 2

 void swap(int *a, int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
  }

// Ponteiros e passagem de argumentos - 3

bool arrayMean(int arr[], int arrLength, double *mean) {
    if (arrLength <= 0) return false;

    double sum = 0;
    for (int i = 0; i < arrLength; i++) {
        sum += arr[i];
    }

    *mean = sum / arrLength;

    return true;
}

 // Ponteiros e passagem de argumentos - 4

bool arrayStats(int arr[], int arrLength, int *min, int *max, double *mean){
    
    if(arrLength <= 0) return false;

    *min = arr[0];
    *max = arr[0];

    for (int i = 1; i < arrLength; i++)
    {
        if(*max < arr[i]){
            *max = arr[i];
        } 
        
        if(*min > arr[i]){
            *min = arr[i];
        }
    }

    arrayMean(arr, arrLength, mean);

    return true;
    
}