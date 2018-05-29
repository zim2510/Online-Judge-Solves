#include <stdio.h>

int main()
{
    int lines,digit;


    scanf("%d", &lines);
    while(lines--){
        scanf("%d", &digit);
        if(digit%2==0) {printf("red\n");}
        else printf("blue\n");
        }


    return 0;
}
