#include <stdio.h>

int isprime(int a);

int main()
{
    int lines, count, i, result, coun;
    int input[10];

    scanf("%d", &lines);

    for(count=0;count<lines;count++){
        i=0;
        while(i<10){
            scanf("%d", &input[i]);
            i++;
            }
        result=0;
        for(coun=0;coun<10;coun++){
            result=result+isprime(input[coun]);
            }
        printf("%d\n", result);


    }

    return 0;
}

int isprime(int a)
{
    int i;
    int prime[]={2, 3, 5, 7, 11 , 13};
    if(a<=1) return 0;
    for(i=0;i<6;i++){
        if(a>=prime[i]*prime[i]){
            if(a%prime[i]==0) return 0;
        }
    }

    return 1;

}
