/*Wap to implement binary search using arrays in C language.
Prerequisites:- Sorted array*/

#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i,key,low,high,mid,flag = 0;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int *arr = (int*)malloc(n * sizeof(int));
    printf("Enter %d elements in sorted order:\n", n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d",&key);
    low = 0;
    high = n - 1;
    while(low <= high){
        mid = (low + high) / 2;
        if(arr[mid] == key){
            printf("Element %d found at index %d\n", key, mid);
            flag = 1;
            break;
        }
        else if(arr[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    if(flag == 0){
        printf("Element %d not found in the array\n", key);
    }
    free(arr);
    return 0;
}