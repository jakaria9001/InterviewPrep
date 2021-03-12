
#include <stdio.h>

int findMinimum(int arr[], int n)
{
    int res = arr[0];
    for (int i = 1; i < n; i++)
        if(arr[i]<res)
            res = arr[i];
    return res;
}
 
int findMaximum(int arr[], int n)
{
    int res = arr[0];
    for (int i = 1; i < n; i++)
        if(arr[i]>res)
            res = arr[i];
    return res;
}
 
int main()
{
    int i,n;
    printf("Enter size of the array : ");
    scanf("%d",&n);
    
    int arr[n];
    printf("Enter elements of the array : \n");
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);
        
    printf("Minimum element of array: %d\n", findMinimum(arr, n) );
    printf("Maximum element of array: %d\n", findMaximum(arr, n) );
    return 0;
}