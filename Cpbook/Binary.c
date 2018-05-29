#include <stdio.h>
#include <math.h>


void binarycall(int a, int b);

int main()
{
    int i, input, rangemin, rangemax;
    
    scanf("%d", &i);
    
    while(i--){
        scanf("%d", &input);
        getchar();
        rangemax= pow(2, input)-1;
        rangemin= pow(2, input-1);
        if(input==1) printf("0\n");
        while(rangemin<=rangemax){
            binarycall(rangemin, input);
            printf("\n");
            rangemin++;
        }
    }
    
    return 0;
}

void binarycall(int rangemin, int input)
{
    int array[11];
    int j=input;
    array[input]='\0';
    while(input--){
        array[input]=rangemin%2;
        rangemin=rangemin/2;
    }
    for(input=0;j>input;input++) printf("%d", array[input]);
}
