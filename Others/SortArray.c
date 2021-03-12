// Q1(ii) Sorting an array  : 

#include <stdio.h>

void sortArrayInAscending(int arr[],int n){
    int i, j,tmp;
    for (i = 0; i < n; ++i){
        for (j = i + 1; j < n; ++j){
            if (arr[i] > arr[j]){
                tmp =  arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    
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
        
    // calling the sort function : 
    sortArrayInAscending(arr,n);
    
    printf("The array sorted in ascending order : \n");
    for(i=0;i<n;i++)
        printf("%d ", arr[i]);
    
    return 0;
}