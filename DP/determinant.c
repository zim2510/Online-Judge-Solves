#include<stdio.h>
#include<math.h>

int main()
{
    float a,b,c,r;
    float f,x1,x2,D;
    scanf("%f %f %f",&a,&b,&c);
    if(a==0)
    {
        x1=-b/c;
        printf("x=%f",x1);
    }
    else
    {
        D=(b*b)-(4*a*c);
        if(D<0)
        {
            printf("Imaginary root");
        }
        else if(D==0)
        {
            x1=-b/(2*a);
            printf("x1 and x2 are equal.\n x1=%f",x1);
        }
        else
        {
            r=sqrt(D);
            x1=(-b+r)/(2*a);
            x2=(-b-r)/(2*a);
            printf("x1=%f    x2=%f",x1,x2);
        }
    }
}
