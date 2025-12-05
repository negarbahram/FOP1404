#include <stdio.h>

int counttIlings(int n){
    if(n == 1) return 1;
    if(n == 2) return 2;

    return counttIlings(n-1) + counttIlings(n - 2);
}
int main(void) {
    int n ;
    scanf("%d" , &n);
    printf("%d" , 2* counttIlings(n));
    return 0;
}
