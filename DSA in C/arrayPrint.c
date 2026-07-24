#include<stdio.h>
#include<stdlib.h>

int main(){

    int n = 0, i = 0;

    printf("Enter the no of elements: ");
    scanf("%d",&n);

    int* arr1 = (int*) malloc(n * sizeof(int));

    if(arr1 != NULL){
        printf("The elements are: ");
        for(i = 0; i < n; i++){
            printf("%d ",arr1[i]);
        }
        return 0;
    }
    else{
        return -1;
    }
}