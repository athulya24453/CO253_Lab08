#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

long closest_power(long n)
{
    if (n == 0)
        return 0;

    int power = 1;
    n = n >> 1;

    while (n != 0)
    {
        n = n >> 1;
        power = power << 1;
    }

    return power;
}

bool isPower(long n)
{
    if (n == 0)
        return false;
    return (n & (n - 1)) == 0;
}

char *counterGame(long n)
{
    if (n == 1)
    {
        return "Richard";
    }

    int count = 0;

    while (n != 1)
    {
        if (isPower(n))
        {
            n /= 2;
        }

        else
        {
            n -= closest_power(n);
        }
        count++;
    }

    if (count % 2 == 1)
    {
        return "Louise";
    }

    else
    {
        return "Richard";
    }
}

int main()
{
    int ans = closest_power(132);
    printf("%d", ans);
}