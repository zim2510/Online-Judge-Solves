#include <stdio.h>
int used[20],number[20];
void permutation(int at, int n){
    int i;
    if(at==n+1){
        for(i=1;i<=n;i++)
            printf("%d ",number[i]);
        printf("\n");
        return ;
    }
    for(i=1;i<=n;i++)if(!used[i]){
        used[i]=1;
        number[at]=i;
        permutation(at+1,n);
        used[i]=0;
    }
}
int main(){

    int at,n;
    scanf("%d%d",&at,&n);
    permutation(at,n);

    return 0;
}
