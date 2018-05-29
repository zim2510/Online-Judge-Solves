#include <stdio.h>

int main()
{
    int i,j,k,count;
    char input[51];

    scanf("%d", &i);
    getchar();

    while(i--){
        gets(input);
        j=strlen(input);
        count=0;
        while(--j){
            if(input[j]=='0') break;
        }
        for(k=0;k<=j;k++){
            if(input[k]=='1') count++;
            else count--;
            if(count<0) {printf("MAGIC\n"); break;}
        }
        if(count>=0) {printf("NORMAL\n");}
    }
    return 0;
}


