#include <stdio.h>

int main(void) {
    int n , m , k;
    scanf("%d" , &n);
    int lefts[1000] ,rights[1000];
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d" , &lefts[i]);
    }
    scanf("%d" , &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d" , &rights[i]);
    }

    int tMax = 0;
    for (int i = 0; i < m; ++i) {
        if(lefts[i] > tMax){
            tMax = lefts[i];
        }
    }

    for (int i = 0; i < k; ++i) {
        if(n - rights[i] > tMax){
            tMax = n - rights[i];
        }
    }

    printf("%d" , tMax);
    return 0;
}
