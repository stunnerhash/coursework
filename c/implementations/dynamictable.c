#include <stdio.h>
#include <stdlib.h>

int size = 0;     
int capacity = 2; 

int* initVector() {
    return (int*)malloc(capacity * sizeof(int)); 
}

int* resizeVector(int* array) {
    capacity *= 2; 
    array = (int*)realloc(array, capacity * sizeof(int));
    if (array == NULL) {
        printf("Memory reallocation failed!\n");
        exit(1);
    }
    return array;
}

int* vectorPush(int* array, int value) {
    if (size == capacity) {
        array = resizeVector(array); 
    }
    array[size++] = value; 
    return array;
}

void vectorPop() {
    if (size > 0) {
        size--; 
    } else {
        printf("Vector is already empty!\n");
    }
}

void printVector(int* array) {
    printf("Vector elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}


int main() {
    
    int* vector = initVector();

    vector = vectorPush(vector, 10);
    vector = vectorPush(vector, 20);
    printVector(vector);

    vector = vectorPush(vector, 30);
    printVector(vector);

    vectorPop();
    printVector(vector);

    printf("Size: %d, Capacity: %d\n", size, capacity);

    // Free the allocated memory
    free(vector);

    return 0;
}
