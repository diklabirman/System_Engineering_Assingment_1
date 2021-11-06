#include <stdio.h>
#include <math.h>

int isPalindrome(int num)
{
    int copy = num;
    int reverse = 0;
    while (copy > 0)
    {
        reverse *= 10;
        int temp = copy % 10;
        reverse += temp;
        copy /= 10;
    }
    if (reverse == num) return 1;
    else return 0;
}

int isArmstrong(int num)
{
    int count = 0;
    int copy = num;
    int sum = 0;
    while (copy > 0)
    {
        count++;
        copy /= 10;
    }
    copy = num;

    while (copy > 0)
    {
        int temp = copy % 10;
        sum += pow(temp, count);
        copy /= 10;
    }
    if (sum == num) return 1;
    else return 0;
}