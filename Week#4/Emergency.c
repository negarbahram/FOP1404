#include <stdio.h>

int main() {
    int s1, d1, s2, d2;
    scanf("%d %d", &s1, &d1);
    scanf("%d %d", &s2, &d2);

    int a,b,c;
    int oddS, oddD, nzD, first, second;

    
    a = s1 % 10;
    b = (s1 / 10) % 10;
    c = (s1 / 100) % 10;
    oddS = (a % 2 != 0) + (b % 2 != 0) + (c % 2 != 0);

    a = d1 % 10;
    b = (d1 / 10) % 10;
    c = (d1 / 100) % 10;
    oddD = (a % 2 != 0) + (b % 2 != 0) + (c % 2 != 0);
    nzD  = (a != 0) + (b != 0) + (c != 0);

    if (oddS < oddD) first = 1;
    else if (oddS == nzD) first = 3;
    else first = 2;
    
    a = s2 % 10;
    b = (s2 / 10) % 10;
    c = (s2 / 100) % 10;
    oddS = (a % 2 != 0) + (b % 2 != 0) + (c % 2 != 0);

    a = d2 % 10;
    b = (d2 / 10) % 10;
    c = (d2 / 100) % 10;
    oddD = (a % 2 != 0) + (b % 2 != 0) + (c % 2 != 0);
    nzD  = (a != 0) + (b != 0) + (c != 0);

    if (oddS < oddD) second = 1;
    else if (oddS == nzD) second = 3;
    else second = 2;
    
    if (first + second >= 4)
        printf("Emergency");
    else
        printf("Safe");

    return 0;
}
