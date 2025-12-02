#include <stdio.h>

int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int A[a], B[b], C[c];
    for (int i = 0; i < a; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < b; i++) {
        scanf("%d", &B[i]);
    }
    for (int i = 0; i < c; i++) {
        scanf("%d", &C[i]);
    }

    int any_service = 0;
    for (int i = 0; i < a; i++) {
        int in_B = 0, in_C = 0;
        for (int j = 0; j < b; j++) {
            if (A[i] == B[j]) {
                in_B = 1;
                break;
            }
        }

        if (!in_B) continue;

        for (int k = 0; k < c; k++) {
            if (A[i] == C[k]) {
                in_C = 1;
                break;
            }
        }
        if (!in_C) {
            any_service = 1;
            printf("%d ", A[i]);
        }
    }

    if (!any_service) printf("No Service");
    return 0;
}