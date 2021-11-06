#include <stdio.h>
#include <math.h>

int palHelper();
int helperArmstrong();

int isPalindrome(int num)
{
    int copy = num;
    int reverse = 0;

    while (copy > 0)
    {
        reverse *= 10;
        reverse += copy % 10;
        copy /= 10;
    }
    int ret = palHelper (num, reverse);
    return ret;
}

int palHelper (int num, int reverse)
{
    if (num % 10 == 0 && reverse == num)
    {
        return 1; //true
    }
    else
    {
        if (num % 10 == 0 && reverse != num)
        {
            return 0; //false
        }
    }
    int digit1 = num % 10;
    int digit2 = reverse % 10;
    if (digit1 != digit2)
    {
        return 0; //false
    }
    num /= 10;
    reverse /= 10;
    return palHelper(num, reverse);
}

int isArmstrong(int num)
{
    int count = 0;
    int copy = num;
    while (copy > 0)
    {
        count++;
        copy /= 10;
    }

    if (helperArmstrong(num, count) == num) return 1;
    else return 0;
}

int helperArmstrong(int num, int count)
{
    if (num == 1) return 1;
    if (num == 0) return 0;

    int digit = num % 10;
    int power = pow(digit, count);
    return power + helperArmstrong(num/10, count);
}

