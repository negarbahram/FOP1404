#include <stdio.h>

int isHarshad (int n) {
    if (!n)
        return 0;
    int sum=0, x=n;
    while (x > 0) {
        sum += x%10;
        x /= 10;
    }
    return n % sum == 0;
}

int sequence (int n) {
    if (n==0)
        return 0;
    if (n<=2)
        return 1;
    int a=0, b=1, c=1;
    for (int i=0; i< n-2; i++) {
        int temp = a;
        c = c + a;
        a = b;
        b = c - temp;
    }
    return c;
}

int interestingNum (int n) {
    int i=0;
    while (n > 0) {
        if (isHarshad(i))
            n--;
        i++;
    }
    return i-1;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", sequence(interestingNum(n)));
    return 0;
}