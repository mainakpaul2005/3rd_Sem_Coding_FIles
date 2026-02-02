#include<stdio.h>
#include<string.h>
#define MAX 100

int main(){
    char str1[MAX];
    char str2[MAX];

    printf("Enter a string to check for palindrome: ");
    scanf("%s", str1);

    int len = strlen(str1);
    for (int i = 0; i < len; i++) {
        str2[i] = str1[len - i - 1];
    }
    str2[len] = '\0';

    if (strcmp(str1, str2) == 0) {
        printf("%s is a palindrome string\n", str1);
    } else {
        printf("%s is NOT a palindrome string\n", str1);
    }

    return 0;
}
