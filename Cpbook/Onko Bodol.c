#include <stdio.h>

int main()
{
    int i,j,k,nostart;
    char input[9];

    scanf("%d", &i);
    getchar();

    while(i--){
        gets(input);
        j=strlen(input);
        nostart=0;
        for(k=0;k<j;k++){
            if((int)input[k]%2==0){
                printf("%c", input[k]+1);
                nostart=1;
            }
            else if((int)input[k]%2==1 && (k==j-1||nostart==1||input[k]!='1')){
                printf("%c", input[k]-1);
                nostart=1;
            }
        }

        printf("\n");


    }
    return 0;
}


