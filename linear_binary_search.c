#include<stdio.h>

int linear_search(int arr[], int size, int element);
int binary_search(int arr[], int size, int element);
void sort(int arr[], int size);

int main()
{
    int arr[] = {4, 5, 5, 2, 7, 43, 23, 4, 12, 35};
    int size = sizeof(arr) / sizeof(int);
    int element;
    printf("Enter the required element: ");
    scanf("%d", &element);

    printf("linear serach: \n");
    int index = linear_search(arr, size, element);
    if (index < 0)
    {   
        printf("%d was not found in the array\n", element);
    }
    else
    {
        printf("%d was found in %dth index\n",  element, index);
    }

    printf("After sorting\n");
    printf("binary search: \n");
    sort(arr, size);

    int q = binary_search(arr, size, element);
    if (q < 0)
    {
        printf("%d not found in array\n", element);
    }
    else
    {
        printf("%d found in %dth index\n", element, q);
    }
}


//Linear search
int linear_search(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

//Binary search
int binary_search(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size;
    
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else  
        {
            high = mid - 1;
        }
    }
    return -1;
}

//Sorting the array
void sort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}