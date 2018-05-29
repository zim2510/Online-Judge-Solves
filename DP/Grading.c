#include<stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    if(a<=100 && a>80)
        printf("a+");
    else if(a>49 && a<80)
        printf("a");
    else if(a>32 && a<50)
        printf("B");
    else if (a<33 && a>=0)
    printf("Fail");


    return 0;

}
