#include <stdio.h>

#define MAX_SIZE 100

int heap[MAX_SIZE];  
int size = 0;       

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapifyUp(int index);

void heapifyDown(int index);

void insert(int value);

int deleteMin();

void printHeap();

int main() {
    insert(10);
    insert(5);
    insert(3);
    insert(2);
    insert(15);
    printf("Heap elements: ");
    printHeap();

    printf("Min: %d\n", deleteMin());
    printf("After deletion: ");
    printHeap();

    return 0;
}

void heapifyUp(int index) {
    // parent of x is equal to (x-1)/2
    // swap x and its parent if x<parent
    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(&heap[(index - 1) / 2], &heap[index]);
        index = (index - 1) / 2;
    }
}

void heapifyDown(int index) {
    // I can explain this more if you want
    while (index * 2 + 1 < size) {
        int left = index * 2 + 1, right = index * 2 + 2;
        int smallest = left;
        if (right < size && heap[right] < heap[left]) smallest = right;
        if (heap[index] <= heap[smallest]) break;
        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}

void insert(int value) {
    heap[size] = value;
    heapifyUp(size);
    size++;
}

int deleteMin() {
    if (size <= 0) return -1;
    int min = heap[0]; 
    heap[0] = heap[size-1]; // replace first(min) element with last element 
    size--;
    heapifyDown(0);
    return min;
}

void printHeap() {
    for (int i = 0; i < size; i++) 
        printf("%d ", heap[i]);
    printf("\n");
}
