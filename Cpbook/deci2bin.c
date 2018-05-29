#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c;
    while(1){
        printf("\nPlease enter the decimal number: ");
        scanf("%lf", &a);
        for(b=0, c=0;a!=0;c++ ){
            if(((int)a)%2==1){
                b=b+1*(pow(10,c));
            }
            a=(int)(a/2);
        }
        printf("The binary expression is: %0.00lf.\n", b);
    }
    getch();
    return 0;

}
