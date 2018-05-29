#include<stdio.h>

int main()
{
    int a,b,c;
    float avg,summation;
    scanf("%d %d %d",&a,&b,&c);
    summation=a+b+c;
    avg=summation/3;
    printf("Sum=%d\n",summation);
    printf("     Average=%f",avg);
    return 0;
}
