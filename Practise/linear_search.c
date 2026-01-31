#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, key, flag = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *) malloc (n * sizeof(int));
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to search: ");
    scanf("%d", &key);

    for(int i =0;i <= n; i++){
        if(arr[i] == key){
            printf("Element found at index %d\n", i);
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Element not found\n");
    }
    return 0;
}