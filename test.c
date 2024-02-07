#include<stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 9;
    int data;
    printf("Enter the value you want to search for: ");
    scanf("%d", &data);
    int mid, beg, end;
    beg = 0;
    end = 8;
    mid = (beg + end)/2;
    while (beg <= end && arr[mid] != data) {
        if (arr[mid] == data) {
            printf("Value found at index ", mid);
            break;
        }
        else if (data < arr[mid]) {
            end = mid - 1;
        }
        else {
            beg = mid + 1;
        }
        mid = (beg + end)/2;
    }
    printf("List of all the values: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("Value not found");

}