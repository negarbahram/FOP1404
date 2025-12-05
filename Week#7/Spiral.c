#include <stdio.h>

void buildSpiral(int n , int A[n][n]){
    int right = n- 1 , left = 0 , top = 0 , bottom = n - 1;
    int counter = 1;
    while (left <= right || top <= bottom){
        for (int i = left; i <= right ; ++i , counter++) {
            A[top][i] = counter;
        }
        top++;
        for (int i = top; i <= bottom ; ++i , counter++) {
            A[i][right] = counter;
        }
        right --;
        for (int i = right;  i >= left ; i-- , counter++) {
            A[bottom][i] = counter;
        }
        bottom--;
        for (int i = bottom; i >= top ; --i , counter++) {
            A[i][left] = counter;
        }
        left++;
    }
}

int find_iAndJ(int st , int fin , int n , int A[n][n] , int scatter[]){
    int find = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(A[i][j] == st){
                scatter[0] = i;
                scatter[1] = j;
                find++;
            }
            if(A[i][j] == fin){
                scatter[2] = i;
                scatter[3] = j;
                find++;
            }
        }
    }
    return find;
}


int main(void) {
    int n;
    scanf("%d" , &n);
    int A[n][n];
    buildSpiral(n , A);

    int st , fin;
    scanf("%d %d" , &st , &fin);


    int scatter[4];
    if(find_iAndJ(st , fin , n , A , scatter)!=2){
        printf("NO PATH FOUND!");
        return 0;
    }

    int i1 = scatter[0] , j1 = scatter[1] , i2 = scatter[2] , j2 = scatter[3];

    if(j1 < j2){
        printf("%d R " , j2 - j1);
    }
    else if(j1 > j2){
        printf("%d L " , j1 - j2);
    }
    if(i1 < i2){
        printf("%d D " , i2 - i1);
    }
    else if(i1 > i2){
        printf("%d U " , i1 - i2);
    }
    return 0;
}

