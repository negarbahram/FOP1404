#include <stdio.h>

void sort(int A[] , int size){
    for(int i = size - 1 ; i > 0; i--){
        int max = 0;
        int idMax = 0;
        for(int j = 0 ; j <= i ; j++){
            if(A[j] > max){
                idMax = j;
                max = A[j];
            }
        }
        int temp = A[i];
        A[i] = A[idMax];
        A[idMax] = temp;
    }
}

void generateSubsets(int index , int arr[] , int n , int current[] , int size){
    if(index == n){
        for (int i = 0; i < size; ++i) {
            printf("%d " , current[i]);
        }
        if(size){
            printf("\n");
        }
        return;
    }

    generateSubsets(index + 1 , arr , n , current , size);//without consider it

    current[size] = arr[index];
    generateSubsets(index + 1 , arr , n , current , size + 1);//consider it
}
int main(void) {
    int n;
    scanf("%d" , &n);
    int arr[20];
    int current[20];
    for (int i = 0; i < n; ++i) {
        scanf("%d" , &arr[i]);
    }

    sort(arr , n);
    generateSubsets(0 , arr , n , current , 0);
    return 0;
}
