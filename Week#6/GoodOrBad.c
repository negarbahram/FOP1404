#include <stdio.h>

int toBinary(int n)
{
    int b = 0, pow = 1;
    while (n > 0)
    {
        b += (n % 2) * pow;
        pow *= 10;
        n /= 2;
    }
    return b;
}

int xorDigits(int a, int b)
{
    return a == b ? 0 : 1;
}

int xorOfBinary(int n)
{
    int b = n % 10;
    n /= 10;
    while (n > 0)
    {
        b = xorDigits(b, n % 10);
        n /= 10;
    }
    return b;
}

int main()
{
    int n, good = 0, a[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
        if (xorOfBinary(toBinary(a[i])))
            good++;
        else
            good--;
    }
    if (good > 0)
        printf("GOOD");
    else
        printf("BAD");
    return 0;
}