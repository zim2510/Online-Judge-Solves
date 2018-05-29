#include <stdio.h>
#include <string.h>

int main()
{
    char input[1000];
    int i, j, k, wordend, count;

    scanf("%d", &i);
    getchar();
    while(i--){
        count=wordend=0;
        gets(input);
        j=strlen(input);
        for(k=0;k<j;k++){
            if((input[k]==' '||input[k]=='.') && wordend==0) {
                wordend=1;
                count++;
            }
            else if(k==j-1 && input[k]!=' ' && input[k]!='.'){
                wordend=1;
                count++;
            }
            else if(input[k]!=' ') wordend=0;
        }
        printf("%d\n", count*420);
    }
    return 0;
}



