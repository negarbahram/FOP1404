#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    int max_sum = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += A[j];
            if (sum > max_sum) {
                max_sum = sum;
            }
        }
    }

    printf("%d", max_sum);
    return 0;
}