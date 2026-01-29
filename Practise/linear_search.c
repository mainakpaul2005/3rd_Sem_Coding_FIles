/*Wap to implement linear search using arrays in C language.*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i,key,flag = 0;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int *arr = (int*)malloc(n * sizeof(int));
    printf("Enter %d elements:\n", n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d",&key);
    for(i=0;i<n;i++){
        if(arr[i] == key){
            printf("Element %d found at index %d\n", key, i);
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Element %d not found in the array\n", key);
    }
    free(arr);
    return 0;
}
