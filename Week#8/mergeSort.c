#include  <stdio.h>

void merge(int A[], int l, int m, int r) {
    int i = l, j = m, k = 0, c[100];
    while (i < m && j < r) {
        if (A[i] < A[j])
            c[k++] = A[i++];
        else
            c[k++] = A[j++];
    }
    while (i < m) c[k++] = A[i++];
    while (j < r) c[k++] = A[j++];
    for (i = l, k = 0; i < r; i++, k++) A[i] = c[k];
}

void mergeSort(int A[], int l, int r) {
    if (r - l == 1)
        return;
    int mid = (l + r) / 2;
    mergeSort(A, l, mid);
    mergeSort(A, mid, r);
    merge(A, l, mid, r);
}

int main() {
    int n;
    int a[100];
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    mergeSort(a, 0, n);
    for (int i = 0; i < n; i++)
        printf("%d ",a[i]);
}