#include <stdio.h>

int main()
{
    int i,j,k,m,n,o,true;
    char ara1[128];
    char ara2[128];

    scanf("%d", &o);
    getchar();

    while(o--){
        scanf("%s", ara1);
        scanf("%s", ara2);

        getchar();

        m=strlen(ara1);
        n=strlen(ara2);
        true=0;


        for(i=0,j=0; i<m && j<n;i++){
            if(ara1[i]==ara2[j]){
                k=i;
                if(m==1||n==1){printf("%d\n", i); true=1;}
                while(n!=1 && i<m && j<n){
                    k++;
                    j++;
                    if(ara1[k]!=ara2[j]) {j=0; break;}
                    else if(j==n-1) {printf("%d\n", i); true=1; break;}
                    else if(k==m-1) {break;}

                }
             if(true==1) break;
            }
        }

    }
    return 0;
}


