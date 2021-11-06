#include <stdio.h>
#include "NumClass.h"


void printArmstrong(int num1, int num2)
{
    printf("The Armstrong numbers are:");
    for(int i = num1 ; i <= num2 ; i++)
    {
        if(isArmstrong(i))
        {
            printf(" %d", i);
        }
    }
    printf("\n");
}

void printPalindrome(int num1, int num2)
{
    printf("The Palindromes are:");
    for(int i = num1 ; i <= num2 ; i++)
    {
        if(isPalindrome(i))
        {
            printf(" %d", i);
        }
    }
    printf("\n");
}

void printPrime(int num1, int num2)
{
    printf("The Prime numbers are:");
    for(int i = num1 ; i <= num2 ; i++)
    {
        if(isPrime(i))
        {
            printf(" %d", i);
        }
    }
    printf("\n");
}

void printStrong(int num1, int num2)
{
    printf("The Strong numbers are:");
    for(int i = num1 ; i <= num2 ; i++)
    {
        if(isStrong(i))
        {
            printf(" %d", i);
        }
    }
    printf("\n");
}



int main()
{
    int num1, num2;
    scanf("%d %d",&num1, &num2);
    if(num1 > num2){
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    printArmstrong(num1, num2);
    printPalindrome(num1, num2);
    printPrime(num1, num2);
    printStrong(num1, num2);

    return 1;
}


