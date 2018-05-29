#include <stdio.h>

int main()
{
    int lines, a , b, c;

    scanf("%d", &lines);

    while(lines--){
        scanf("%d %d %d", &a, &b, &c);
        if(a*2<=b&&a*2<=c) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
