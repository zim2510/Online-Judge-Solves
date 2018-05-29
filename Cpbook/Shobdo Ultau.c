#include <stdio.h>

int main()
{
    int i,temp,rangem,rangex;
    char input[151];

    scanf("%d", &i);
    getchar();

    while(i--){
        gets(input);
        rangem=rangex=strlen(input);

        for(rangem=rangex-1; rangem>-2;rangem--){
            if(input[rangem]==' '||rangem==-1){
            temp=rangem;
            while(rangem<rangex-1)
            {
                printf("%c", input[++rangem]);
            }
            rangem=rangex=temp;
            printf(" ");
            }


        }
        printf("\n");


    }
    return 0;
}

