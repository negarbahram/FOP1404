#include <stdio.h>

int main() {
    int n, k, l, c, d, p, nl, np;
    scanf("%d %d %d %d %d %d %d %d", &n, &k, &l, &c, &d, &p, &nl, &np);

    int total_drink = k * l;        
    int total_lime = c * d;        
    int total_salt = p;            

    int drink = total_drink / (nl * n);  
    int lime = total_lime / n;    
    int salt = total_salt / (np * n);    

    int max_toasts = drink;
    if (lime < max_toasts) max_toasts = lime;
    if (salt < max_toasts) max_toasts = salt;


    printf("%d\n", max_toasts);

    return 0;
}
