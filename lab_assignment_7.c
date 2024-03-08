#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int* bubbleSort(int arr[]) {
    int i, j;
    int* elementSwaps = (int*) malloc (sizeof(int)*SIZE);
    for(int i = 0; i < SIZE; i++){
        elementSwaps[i] = 0;
    }
    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                elementSwaps[j]++; // Increment swaps for this element
                elementSwaps[j + 1]++;
                swap(arr, j, j + 1);
                swap(elementSwaps, j, j + 1);
            }
        }
    }
    return elementSwaps;
}

int* selectionSort(int arr[]) {
    int i, j, minIndex;
    int* elementSwaps = (int*)malloc(sizeof(int)*SIZE);
    for(int i = 0; i < SIZE; i++){
        elementSwaps[i] = 0;
    }
    for (i = 0; i < SIZE - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < SIZE; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if(minIndex == i) continue;
        
        elementSwaps[i]++;
        elementSwaps[minIndex]++;
        swap(arr , i, minIndex);
        swap(elementSwaps, i, minIndex);
    
    }

    return elementSwaps;
}

int main() {
    int counter = 0;

    int bubbleArray1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int bubbleArray2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    int selectionArray1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int selectionArray2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    printf("array1: \n\n");
    int* bubbleSwapCount1 = bubbleSort(bubbleArray1);

    for(int index = 0; index < SIZE; index++) {
        printf("%d: %d\n", bubbleArray1[index], bubbleSwapCount1[index]);
        counter+= bubbleSwapCount1[index];
    }
    free(bubbleSwapCount1);
    printf("Total swaps: %d\n", counter/2);
    counter = 0;

    int* selectionSwapCount1 = selectionSort(selectionArray1);

    for(int index = 0; index < SIZE; index++) {
        printf("%d: %d\n", selectionArray1[index], selectionSwapCount1[index]);
        counter+= selectionSwapCount1[index];
    }
    free(selectionSwapCount1);
    printf("Total swaps: %d\n", counter/2);
    counter = 0;


    printf("array2: \n\n");

    int* bubbleSwapCount2 = bubbleSort(bubbleArray2);

    for(int index = 0; index < SIZE; index++) {
        printf("%d: %d\n", bubbleArray2[index], bubbleSwapCount2[index]);
        counter+= bubbleSwapCount2[index];
    }
    free(bubbleSwapCount2);
    printf("Total swaps: %d\n", counter/2);
    counter = 0;


    int* selectionSwapCount2 = selectionSort(selectionArray2);

    for(int index = 0; index < SIZE; index++) {
        printf("%d: %d\n", selectionArray2[index], selectionSwapCount2[index]);
        counter+= selectionSwapCount2[index];
    }
    free(selectionSwapCount2);
    printf("Total swaps: %d\n", counter/2);
    counter = 0;

}