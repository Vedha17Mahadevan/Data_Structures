//B23CS1262
//Vedha Mahadevan 
//Sorting : Quick , Merge , Heap (Menu Driven)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int index = (low - 1);
    for (int i = low; i < high; i++) {
        if (a[i] < pivot) {
            index++;
            swap(&a[index], &a[i]);
        }
    }
    swap(&a[index + 1], &a[high]);
    return (index + 1);
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(a, low, high);
        quickSort(a, low, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, high);
    }
}

void merge(int a[], int left, int middle , int right) {
    int leftSize = middle - left + 1;
    int rightSize = right - middle;
    int Larray[leftSize], Rarray[rightSize];
    
    for (int i = 0; i < leftSize; i++){
        Larray[i] = a[left + i];
    }
    for (int j = 0; j < rightSize; j++){
        Rarray[j] = a[middle + 1 + j];
    }
    
    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (Larray[i] <= Rarray[j]) {
            a[k] = Larray[i];
            i++;
        } 
        else {
            a[k] = Rarray[j];
            j++;
        }
        k++;
    }
    while (i < leftSize) {
        a[k] = Larray[i];
        i++;
        k++;
    }
    while (j < rightSize) {
        a[k] = Rarray[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(a, left, middle);
        mergeSort(a, middle + 1, right);
        merge(a, left, middle, right);
    }
}

void heapify(int a[], int size, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < size && a[left] > a[largest]){
        largest = left;
    }
    if (right < size && a[right] > a[largest]){
        largest = right;
    }
    if (largest != index) {
        swap(&a[index], &a[largest]);
        heapify(a, size, largest);
    }
}

void heapSort(int a[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(a, size, i);
    for (int i = size - 1; i > 0; i--) {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

void printArray(int a[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void main() {
    
    int a[MAX], size , choice;
    
    printf("Enter the size array : ");
    scanf("%d", &size);
    printf("\nEnter Array elements : \n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }
    printf("\nArray : ");
    for (int i=0 ; i<size ; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    
    int arrCopy[size];
    for (int i = 0; i < size; i++){
        arrCopy[i] = a[i];
    }
    
    while (true) {
        printf("\nSORTING Menu\n");
        printf("1. Quick Sort\n");
        printf("2. Merge Sort\n");
        printf("3. Heap Sort\n");
        printf("4. Exit\n");
        
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            quickSort(arrCopy, 0, size - 1);
            printf("\nArray sorted with Quick Sort : ");
            printArray(arrCopy, size);
        } 
        else if (choice == 2) {
            mergeSort(arrCopy, 0, size - 1);
            printf("\nArray sorted with Merge Sort : ");
            printArray(arrCopy, size);

        } 
        else if (choice == 3) {
            heapSort(arrCopy, size);
            printf("\nArray sorted with Heap Sort :");
            printArray(arrCopy, size);
        } 
        else if (choice == 4) {
            printf("\nExiting Menu...");
            break;
        } 
        else {
            printf("\nInvalid choice , Try again !!!");
        }
    }
}

/* OUTPUT

Enter the size array : 7

Enter Array elements : 
3
1
2
3
2
1
3

Array : 3 1 2 3 2 1 3 

SORTING Menu
1. Quick Sort
2. Merge Sort
3. Heap Sort
4. Exit

Enter your choice : 1

Array sorted with Quick Sort : 1 1 2 2 3 3 3 

SORTING Menu
1. Quick Sort
2. Merge Sort
3. Heap Sort
4. Exit

Enter your choice : 2

Array sorted with Merge Sort : 1 1 2 2 3 3 3 

SORTING Menu
1. Quick Sort
2. Merge Sort
3. Heap Sort
4. Exit

Enter your choice : 3

Array sorted with Heap Sort :1 1 2 2 3 3 3 

SORTING Menu
1. Quick Sort
2. Merge Sort
3. Heap Sort
4. Exit

Enter your choice : 4

Exiting Menu...


Enter the size array : 5

Enter Array elements : 
5
3
8
1
2

Array : 5 3 8 1 2 

SORTING Menu
1. Quick Sort
2. Merge Sort
3. Heap Sort
4. Exit

Enter your choice : 1

Array sorted with Quick Sort : 1 2 3 5 8 

SORTING Menu
1. Quick Sort
2. Merge Sort
3. Heap Sort
4. Exit

Enter your choice : 2

Array sorted with Merge Sort : 1 2 3 5 8 

SORTING Menu
1. Quick Sort
2. Merge Sort
3. Heap Sort
4. Exit

Enter your choice : 3

Array sorted with Heap Sort :1 2 3 5 8 

SORTING Menu
1. Quick Sort
2. Merge Sort
3. Heap Sort
4. Exit

Enter your choice : 4

Exiting Menu...

*/