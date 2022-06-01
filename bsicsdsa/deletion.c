#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int n)
{

    // traversal
    for (int i = 0; i <n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void inddeletion(int arr[], int size, int index)
{
    // code for deletion
 
    for (int i = index; i <size-1;  i++)
    {
        arr[i ] = arr[i+1];
    }

}
int main()
{
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, index = 1;
    display(arr, size);
    inddeletion(arr, size, index);
    size -= 1;
    display(arr, size);
    return 0;
}