#include <stdio.h>
#include <math.h>

int n , m;
int isValid(int i , int j){
    return i >= 0 && i < n && j >= 0 && j < m;
}

int countingSquare(int A[n][m]){
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (A[i][j] == 1){
                int maxLen = fmin(n - i , m - j);
                for (int k = 1; k <= maxLen; ++k) {
                    int sw = 1;
                    if(!isValid(i + k , j) || !isValid(i , j + k)){
                        sw = 0;
                    }
                    for (int l = i; l <= i + k && sw; ++l) {
                        if(A[l][j] != 1 || A[l][j + k] != 1) {
                            sw = 0;
                        }
                    }
                    for (int l = j; l <= j + k && sw; ++l) {
                        if(A[i + k][l] != 1 || A[i][l] != 1){
                            sw = 0;
                            break;
                        }
                    }
                    if(sw) res++;
                }
            }
        }
    }
    return res;
}

int contingRotatedSquare(int A[n][m]){
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (A[i][j] == 1){
                int maxLen = fmin(m -j , j);
                for (int k = 1; k <= maxLen; ++k) {
                    int sw = 1;
                    if(!isValid(i + k , j) || !isValid(i , j + k)){
                        sw = 0;
                    }
                    for (int l = i , r = j ; l <= i + k && r <= j + k && sw; ++l , ++r) {
                        if(A[l][r] != 1 || A[l][2 * j - r] != 1) {
                            sw = 0;
                        }
                    }
                    for (int l = i + 2*k , r = j; l >= i + k && r <= j + k && sw; --l , r++) {
                        if(A[l][r] != 1 || A[l][2 * j -r] != 1) {
                            sw = 0;
                        }
                    }
                    if(sw) res++;
                }
            }
        }
    }
    return res;
}

int main(void) {
    scanf("%d %d" , &n , &m);
    int A[n][m];
    int sumOfOne[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sumOfOne[i][j]=0;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d" , &A[i][j]);
        }
    }

    printf("%d" , countingSquare(A) + contingRotatedSquare(A));
    return 0;
}
