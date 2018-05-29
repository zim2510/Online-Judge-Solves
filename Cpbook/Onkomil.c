#include <stdio.h>

int main()
{
    int lines,i, coun;
    char input[3];
    char input2[3];
    scanf("%d", &lines);
    for(i=0;i<lines;i++){
        scanf("%s %s", input, input2);
        coun=0;
        if(input[0]<input[1]){
            if(input[0]==input2[0]||input[0]==input2[1]) {printf("%c", input[0]); coun++;}
            if(input[1]==input2[0]||input[1]==input2[1]) {printf("%c", input[1]); coun++;}
        }
        else if(input[1]<input[0]){
            if(input[1]==input2[0]||input[1]==input2[1]) {printf("%c", input[1]); coun++;}
            if(input[0]==input2[0]||input[0]==input2[1]) {printf("%c", input[0]); coun++;}
        }
        else if(input[1]==input[0]){
            if(input[1]==input2[0]||input[1]==input2[1]) {printf("%c", input[1]); coun++;}
        }
        if(coun==0){printf("N\n");}
        else printf("\n");

    }
    return 0;
}

