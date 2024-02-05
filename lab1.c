#include <stdio.h>

void change_a(int *a) {
    *a = 10; // changes value of address of a to 10
}

void change_contents(char arr[], int index, int value) 
{
    // pass in an array
    arr[index] = value;
}

void print_list(int arr[])
{
    // initialize i to 0, run the loop while i < 5, and increase i by 1 every time;
    // Here, i++ is the same as i = i + 1
    for(int i = 0; i < 1; i++){
        printf("%d ", arr[i]);
    }
}

void insertion_sort(int arr[], int length) 
{
    // compare two elements at a time

    // Length of array: complete size of array / size of the first element 
    // = number of elements in array
    int i, temp, j;

    for (i = 1; i < length; i++) {
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && (arr[j] > temp)) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = temp;
    }
}

int string_length(char *str) {
    int len = 0;
    for (; str[len] != '\0'; len++);
    return len; 

    // O(n), goes through every char address
}


void seq_replace(int *arr1, unsigned long arr1_sz, int *arr2, unsigned long arr2_sz) {
    for (int a = 0; a < arr1_sz; a++) {
        for (int b = 0; b < arr2_sz; b++) {
            if (arr1[a] == arr2[b]) {
                arr1[a] = 0;
            }
        }
    }
    // goes through every element of arr1 
    // each element gets arr2_sz comparisons 
    // O(arr1_sz * arr2_sz) approximately O(n^2)
}

int main()
{
    // Question 2
    int a = 5; 
    printf("%p\n", &a);
    change_a(&a); // passes address of a
    printf("%d\n", a);
    
    // Question 3
    char arr[100] = {0}; 
    // zeroing effect, all values initialized to 0
    printf("%d\n", arr[99]);
    // arr is implicitly a pointer to the array 
    printf("Arr address: %ld\n", arr);
    change_contents(arr, 1, 100); 
    printf("%d\n", arr[0]);
    printf("%d\n", arr[1]);

    int int_arr[5] = {5, 4, 3, 2, 1}; 
    print_list(int_arr);
    int length = sizeof(int_arr) / sizeof(int_arr[0]);

    insertion_sort(int_arr, length); 
    printf("\n");
    print_list(int_arr);

    char *str = "hello allan";
    printf("\n%d\n", string_length(str));

    int arr_1[] = {1};
    int arr_2[] = {1};
    seq_replace(arr_1, 1, arr_2, 1);

    print_list(arr_1);

    return 0; 
}