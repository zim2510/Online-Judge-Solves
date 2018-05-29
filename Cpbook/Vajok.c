#include <stdio.h>
#include <math.h>

int main()
{
    int d,i,k,l,j,input;
    scanf("%d", &i);
    getchar();
    d=i;
    while(i--){
        scanf("%d", &input);
        getchar();
        printf("Case %d:", d-i);
        j=sqrt(input);
        k=1;
        while(k<=j){
            if(input%k==0) printf(" %d",k);
            k++;
        }
        while(k--){
            l=input/k;
            if(k!=l && l!=0 && input%l==0) printf(" %d", l);
            if(l==input) break;

        }

        printf("\n");
    }

    return 0;
}


