#include <stdio.h>
#include <limits.h>

void sort(int A[] , int size){
    for(int i = size - 1 ; i > 0; i--){
        int min = INT_MAX;
        int idMin = 0;
        for(int j = 0 ; j <= i ; j++){
            if(A[j] < min){
                idMin = j;
                min = A[j];
            }
        }
        int temp = A[i];
        A[i] = A[idMin];
        A[idMin] = temp;
    }
}

void spiral(int A[] , int size){
    int right = size - 1 , left = 0 , top =  0 , bottom = size - 1;
    int result[size][size];
    int counter = 0;
    while (left <= right || top <= bottom){
        for (int i = right;  i >= left ; i-- , counter++) {
            result[top][i] = A[counter];
        }
        top++;
        for (int i = top; i <= bottom ; ++i , counter++) {
            result[i][left] = A[counter];
        }
        left++;
        for (int i = left; i <= right ; ++i , counter++) {
            result[bottom][i] = A[counter];
        }
        bottom --;
        for (int i = bottom; i >= top ; --i , counter++) {
            result[i][right] = A[counter];
        }
        right--;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d " , result[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int n;
    scanf("%d" , &n);
    int A[n * n + 1];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d" , &A[n * i + j]);
        }
    }
    sort(A,n*n);
    spiral(A , n);

    return 0;
}
