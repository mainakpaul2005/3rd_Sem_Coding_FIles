#include<stdio.h>
#define MAX 100

int fact(int num);

int main()
{
	int arr[MAX];
	int n, i;

	printf("Enter the number of elements: ");
	scanf("%d",&n);

	printf("Enter the number: \n");
	for (i = 0; i < n; ++i){
		scanf("%d",&arr[i]);
	}

	printf("The elements are: \n");
	for (i = 0; i < n; ++i){
		printf("%d ",arr[i]);
	}
	return 0;
}

int fact(int num){
	if (num == 0)
		return 0;
	else 
		return num * fact(num - 1);
}