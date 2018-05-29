#include <stdio.h>

int main()
{
    int lines,digit,height,iteration,i,j;


    scanf("%d", &lines);
    j=lines;
    while(lines--){
        scanf("%d %d", &digit, &height);
        printf("Case %d:\n", j-lines);
        for(iteration=1;iteration<=height;iteration++){
            for(i=0;i<iteration;i++){
                printf("%d",digit);
            }
            printf("\n");
        }
    }

    return 0;
}
