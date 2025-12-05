#include <stdio.h>

long long tripleFactorial(int n) {
    long long result  = 1;
    while (n >= 3) {
        result *= n;
        n -= 3;
    }
    return result;
}

int countZero (long long n) {
    int cnt=0;
    while (n%10 == 0 && n!= 0) {
        cnt++;
        n /= 10;
    }
    return cnt;
}


int main() {
    int n, k, a[100];
    scanf("%d%d", &n,&k);
    int sw=1;
    for (int i=0; i<n; i++) {
        scanf("%d", a+i);
        if (countZero(tripleFactorial(a[i])) >= k) {
            printf("%d ", a[i]);
            sw = 0;
        }
    }
        if (sw)
            printf("-1");
    return 0;
}