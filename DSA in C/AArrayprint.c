#include<stdio.h>
#include<stdlib.h>

int main()
{
	int* arr;
	int size,i;
	
	printf("ENter the no of numbers : ");
	scanf("%d",&size);
	
	arr = (int* ) malloc(size * sizeof(int));
	
	printf("Enter the numbers: ");
	
	for( i = 0; i < size; i++)
	{
		scanf("%d",&arr[i]);
	}
	
	printf("The Entered Numbers are : ");
	
	for( i = 0 ; i < size; i++)
	{
		printf(" %d ",arr[i]);
	}
	
}