/*Wap to implement binary search using arrays in C language.
Prerequisites:- Sorted array
*/

#include<stdio.h>
#include<stdlib.h>

int main(){

    int n, i, key, flag, high, low, mid;

    flag = 0;

    printf("Enter the number of elements: ");
    scanf("%d",&n);

    int* arr = (int*) malloc(n * sizeof(int));

    printf("Enter the elements: \n");
    for(i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d",&key);

    low = 0;
    high = n -1;
    
    while(low <= high){
        mid = (low + high)/2;
        if (arr[mid] == key){
            flag = 1;
            break;
        }
        else if (key < arr[mid]){
            high = mid - 1;
            continue;
        }
        else{
            low = mid + 1;
            continue;
        }
    }
    
    mid++;

    if (flag == 1){
        printf("Element found at %d index.",mid);
    }
    else{
        printf("Element NOT found!!");
    }

    return 0;
}