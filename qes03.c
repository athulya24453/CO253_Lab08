#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int k, n;
    char *t;
    int *r;

    scanf("%d %d", &n, &k);

    t = (char *)malloc(sizeof(int) * (n + k - 1));
    r = (int *)malloc(sizeof(int) * n);

    scanf("%c", t);

    for (int i = 0; i < n + k - 1; i++)
        scanf("%c", t + i);
    r[0] = t[0] - 48;

    for (int i = 1; i < k; i++)
    {
        r[i] = (t[i - 1] - 48) ^ (t[i] - 48);
    }

    for (int i; i < n - k; i++)
    {
        r[i] = r[i - k] ^ (t[i - 1] - 48) ^ (t[i] - 48);
    }

    r[n - 1] = (t[n + k - 2] - 48);

    for (int i = 1; i < k; i++)
    {
        r[n - 1 - i] = (t[n + k - i - 1] - 48) ^ (t[n + k - 2 - i] - 48);
    }

    for (int i = 0; i < n; i++)
        printf("%d", r[i]);
    return 0;
}