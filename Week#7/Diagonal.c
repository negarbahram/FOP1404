#include <stdio.h>

void sortRows(int row, int col, int A[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col - 1; j++) {
            int min_index = j;
            for (int k = j + 1; k < col; k++) {
                if (A[i][k] < A[i][min_index]) {
                    min_index = k;
                }
            }
            int temp = A[i][j];
            A[i][j] = A[i][min_index];
            A[i][min_index] = temp;
        }
    }
}

void printDiagonal(int rows, int cols, int arr[][cols]) {
    for (int s = 0; s <= rows + cols - 2; s++) {
        int first = 1;

        for (int i = 0; i < rows; i++) {
            int j = s - i;
            if (j >= 0 && j < cols) {
                if (!first) {
                    printf(" ");
                }
                printf("%d", arr[i][j]);
                first = 0;
            }
        }
        printf("\n");
    }
}

int main(void) {
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    int A[rows][cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    sortRows(rows, cols, A);
    printDiagonal(rows, cols, A);

    return 0;
}
