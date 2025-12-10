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

void insertLayer(int n , int matrix[][n], int layer, int values[]){
    int right = n - layer - 1 , left = layer , top =  layer , bottom = n - layer - 1;
    int counter = 0;
    for (int i = left; i <= right ; ++i , counter++) {
        matrix[top][i] = values[counter];
    }
    top ++;
    for (int i = top; i <= bottom ; ++i , counter++) {
        matrix[i][right] = values[counter];
    }
    right --;
    for (int i = right; i >= left ; --i , counter++) {
        matrix[bottom][i] = values[counter];
    }
    bottom--;
    for (int i = bottom; i >= top ; i-- , counter++) {
        matrix[i][left] = values[counter];
    }
    left--;
}

void extractLayer(int n , int matrix[][n], int layer, int values[]){
    int right = n - layer - 1, left = layer , top =  layer , bottom = n - layer - 1;
    int counter = 0;
    for (int i = left; i <= right ; ++i , counter++) {
        values[counter] = matrix[top][i];
    }
    top ++;
    for (int i = top; i <= bottom ; ++i , counter++) {
        values[counter] = matrix[i][right] ;
    }
    right --;
    for (int i = right; i >= left ; --i , counter++) {
        values[counter] = matrix[bottom][i];
    }
    bottom--;
    for (int i = bottom; i >= top ; i-- , counter++) {
        values[counter] = matrix[i][left];
    }
    left--;
}

void sortAndFillLayerRec(int n ,int matrix[][n], int layer){
    if(layer >= n / 2) {
        return;
    }
    int values[n*n];
    extractLayer(n , matrix , layer , values);

    int size = (n - 2*layer) * 4 - 4;
    if (size <= 0) size = 1;
    sort(values , size);

    insertLayer(n , matrix , layer , values);

    sortAndFillLayerRec(n , matrix , layer + 1);
}

int main(void) {
    int n;
    scanf("%d" , &n);
    int matrix[n][n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d" , &matrix[i][j]);
        }
    }

    sortAndFillLayerRec(n , matrix , 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d " , matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}