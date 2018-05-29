#include <stdio.h>

int main()
{
    int lines, count,j;
    double a, b, c, i;

    scanf("%d", &lines);

    j=lines;

    while(lines--){
        scanf("%lf %lf %lf",&a, &b, &c);
        printf("Case %d: ", j-lines);
        count=0;
        i=b/a;
        if((c/b)==i) count=count+3;
        i=a-b;
        if((b-c)==i) count=count+2;
        if(count==5) printf("Both\n");
        else if(count==2) printf("Arithmetic Progression\n");
        else if(count==3) printf("Geometric Progression\n");
        else printf("None\n");
    }

    return 0;
}
