#include <stdio.h>

int main()
{
    int a,b,i,j;

    scanf("%d", &i);
    j=i;
    while(i--){
        scanf("%d %d", &a, &b);
        printf("Case %d: %d\n", j-i,a*b);
    }
    return 0;

}