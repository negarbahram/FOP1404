#include <stdio.h>

int isPrime (int x) {
    for (int i = 2; i <= x/2; i++) {
        if (x%i==0) {
            return 0;
        }
    }
    return 1;
}

int humiliate (int x) {
    int cnt = 0;
    while (x > 1) {
        (x & 1) ? (x++) : (x /= 2);
        cnt++;
    }
    return cnt;
}

int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for (int i=2; i<=n; i++) {
        if (isPrime(i) && !(n%i)) {
            cnt += humiliate(i);
        }
    }
    printf("%d", cnt);
    return 0;
}