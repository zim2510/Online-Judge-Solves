#include <stdio.h>


int main()
{
    int lines,i;
    double a, b, c;
    double present, required;
    scanf("%d", &lines);
    for(i=0; i<lines; i++){
        scanf("%lf %lf %lf", &a, &b, &c);
        if(c>300) break;
        present=b/(300-c)*6;
        required=6*(a-b+1)/c;
        printf("%.2lf %.2lf\n",present, required);
    }
    return 0;
}
