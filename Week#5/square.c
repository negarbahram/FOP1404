#include <stdio.h>

int is_square(int number) {
    for (int i = 1; i <= number; i++) {
        int square = i * i;
        if (square == number) return 1;
        if (square > number) return 0;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += A[j];
            if (is_square(sum)) result++;
        }
    }

    printf("%d", result);
    return 0;
}