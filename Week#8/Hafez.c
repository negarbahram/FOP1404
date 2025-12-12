#include  <stdio.h>

int res[1000000][22];
int cnt;

int comp(int a, int b, int len) {
    for (int i = 0; i < len; i++) {
        if (res[a][i + 1] > res[b][i + 1])
            return 1;
        else if (res[a][i + 1] < res[b][i + 1])
            return 0;
    }
}

void swap(int a, int lenA, int b, int lenB) {
    int c[22];
    for (int i = 0; i <= lenA; i++)
        c[i] = res[a][i];
    for (int i = 0; i <= lenB; i++)
        res[a][i] = res[b][i];
    for (int i = 0; i <= lenA; i++)
        res[b][i] = c[i];
}

void sort() {
    for (int i = 0; i < cnt; i++)
        for (int j = i + 1; j < cnt; j++) {
            if (res[i][0] > res[j][0])
                swap(i, res[i][0], j, res[j][0]);
            else if (res[i][0] == res[j][0] && comp(i, j, res[j][0]))
                swap(i, res[i][0], j, res[j][0]);
        }
}

void add(int a[], int n) {
    res[cnt][0] = n;
    for (int i = 0; i < n; i++)
        res[cnt][i + 1] = a[i];
    cnt++;
}

void generateHafez(int A[], int B[], int c[], int sA, int sB, int nA, int nB, int len, int flag) {
    if (flag == 1) {
        if (len)
            add(c, len + 1);
        for (int i = sA; i < nA; i++) {
            if (! len) {
                c[len] = A[i];
                generateHafez(A, B, c, sA + 1, sB, nA, nB, len, 1 - flag);
            }
            else if (A[i] > c[len]) {
                c[len + 1] = A[i];
                generateHafez(A, B, c, sA + 1, sB, nA, nB, len + 1, 1 - flag);
            }
        }
    }
    else {
        for (int i = sB; i < nB; i++) {
            if (B[i] > c[len]) {
                c[len + 1] = B[i];
                generateHafez(A, B, c, sA, sB + 1, nA, nB, len + 1, 1 - flag);
            }
        }
    }
}

int main() {
    int n, m;
    int a[12], b[12];
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    for (int i = 0; i < m; i++)
        scanf("%d",&b[i]);
    int c[22];
    generateHafez(a, b, c, 0, 0, n, m, 0, 1);
    sort();
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < res[i][0]; j++) {
            printf("%d ", res[i][j + 1]);
        }
        printf("\n");
    }
}