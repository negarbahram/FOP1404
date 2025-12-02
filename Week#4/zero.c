/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    int cnt = 0;
    
    if (b % 10 != a % 10) {
        cnt++;
        if (b % 10 != 0) {
            printf("NO");
            return 0;
        }
    }
    
    a /= 10;
    b /= 10;
    if (b % 10 != a % 10) {
        cnt++;
        if (b % 10 != 0) {
            printf("NO");
            return 0;
        }
    }
    
    a /= 10;
    b /= 10;
    if (b % 10 != a % 10) {
        cnt++;
        if (b % 10 != 0) {
            printf("NO");
            return 0;
        }
    }
        
    if (cnt < 3)
        printf("YES");
    else
        printf("NO");
}