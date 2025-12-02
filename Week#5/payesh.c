#include <stdio.h>

int main(void) {
    int n, A[15];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    int streak = 1, sign = 0, answer = 0;
    for (int i = 0; i < n - 1; i++) {
        int newSign = 0;
        if (A[i] < A[i + 1]) newSign = 1;
        if (A[i] > A[i + 1]) newSign = -1;

        if (newSign == 0) {
            streak = 1;
        }
        else if (newSign == sign) {
            streak = 2;
            sign = newSign;
        }
        else {
            streak++;
            sign = newSign;
        }
        if (streak > answer) answer = streak;
    }

    if (answer >= 3) printf("%d", answer);
    else printf("0");
    return 0;
}