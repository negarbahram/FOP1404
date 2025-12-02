#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int A[15];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    int has_answer = 0;

    for (int i = 0; i < n; i++) {
        int start;
        if (i - k < 0) start = 0;
        else start = i - k;

        int is_ascending = 1;
        for (int j = start; j < i; j++) {
            if (A[j] >= A[j+1]) {
                is_ascending = 0;
                break;
            }
        }
        if (!is_ascending) continue;

        int is_descending = 1;
        for (int j = i ; j < i + k && j < n - 1; j++) {
            if (A[j] <= A[j+1]) {
                is_descending = 0;
                break;
            }
        }
        if (is_descending) {
            has_answer = 1;
            printf("%d ", i);
        }
    }

    if (!has_answer) printf("-1");
    return 0;
}