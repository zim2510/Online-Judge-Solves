#include <stdio.h>

int main()
{
    int lines,i, count;
    int n1,n2,m1,m2,input1,input2;
    scanf("%d", &lines);
    for(i=0;i<lines;i++){
        scanf("%d %d", &input1, &input2);
        count=0;
        n1=input1%10;
        n2=input1/10;
        m1=input2%10;
        m2=input2/10;

        if(n1<n2){
            if(n1==m1||n1==m2) {printf("%d",n1); count++;}
            if(n2==m1||n2==m2) {printf("%d",n2); count++;}
        }

        else if(n2<n1){
            if(n2==m1||n2==m2) {printf("%d",n2); count++;}
            if(n1==m1||n1==m2) {printf("%d",n1); count++;}
        }

        else if(n2==n1){
            if(n2==m1||n2==m2) {printf("%d",n2); count++;}

        }
        if(count==0){printf("N\n");}
        else printf("\n");

    }
    return 0;
}

