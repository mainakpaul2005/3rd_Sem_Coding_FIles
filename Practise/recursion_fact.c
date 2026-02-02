#include<stdio.h>

int fact(int num);

int main(){

	int n, res;

	printf("Enter a number: ");
	scanf("%d",&n);

	res = fact(n);

	printf("The Factorial of %d is %d",n,res );
	return 0;
}

int fact(int num){
	if (num == 0)
		return 1;
	else 
		return num * fact(num - 1);
}