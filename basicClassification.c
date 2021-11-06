#include <stdio.h>
#include <math.h>

int isStrong(int num)
{
    int copy = num;
    int sum = 0;
    while (copy > 0)
    {
        int mod = copy % 10;
        int tempSum = 1;
        for (int i = 2; i <= mod; i++)
        {
            tempSum *= i;
        }
        sum += tempSum;
        copy /= 10;
    }
    if (sum == num) return 1;
    else return 0;
}

int isPrime(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        return 0;
    }
    return 1;
}