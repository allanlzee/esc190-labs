#include <stdio.h> 
#include <stdlib.h>

int linear_search(int *a, int sz, int elem) 
{
    // Return first occurence.
    int i = 0; 
    for (; i < sz; i++) {
        if (a[i] == elem) return i;
    }

    // Element not in list.
    return -1;
}


void reverse_arr(int *arr, int sz) 
{
    for (int i = 0; i < sz / 2; i++) {
        int temp = arr[i]; 
        arr[i] = arr[sz - i - 1];
        arr[sz - i - 1] = temp; 
    }
}


int main() 
{
    // Q0
    printf("Hello World!\n");

    int a[] = {3, 2, 3, 4, 3}; 
    printf("%d\n", linear_search(a, sizeof(a) / sizeof(a[0]), 4)); 

    int arr[] = {5, 6, 7, 8, 9, 1}; 

    reverse_arr(arr, sizeof(arr) / sizeof(arr[0])); 
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d ", arr[i]);
    }
}