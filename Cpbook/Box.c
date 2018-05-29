#include <stdio.h>
int main()
{
    int lines,i,input,total,count;
    scanf("%d", &lines);
    for(i=0;i<lines;i++){
        scanf("%d", &input);
        total=input*input;
        for(count=1;count<=total;count++){
            printf("*");
            if(count%input==0) printf("\n");
            if(count==total) printf("\n");
        }
    }
    return 0;
}

