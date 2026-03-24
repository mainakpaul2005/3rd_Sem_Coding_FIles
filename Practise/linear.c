#include<stdio.h>

int main(){
    int arr[] = {6,9,2,5,7};
    int key = 1;
    int i = 0; 
    int size = sizeof(arr)/sizeof(arr[0]);

    for(i = 0; i < size; i++){
        if (arr[i] == key){
            printf("Element found at %d index",i);
            return 0;
        }
    }
    printf("Not Found");
    return 0;
}