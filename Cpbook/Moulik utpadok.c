#include <stdio.h>
int main()
{
    int number,a,b,x,m;
    int prime[54]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251};



    while(1){

        b=0;


        scanf("%d", &number);
        getchar();
            if(number<2) break;
            printf("%d =", number);
            x=1;
            for(a=0, m=number; a<55 && prime[a]<=m ;){
                for(b=0;m%prime[a]==0 && m!=1;){
                    b++;
                    m=m/prime[a];
                }
                if(b!=0 && x==1) { printf(" %d^%d", prime[a], b); x++;}

                else if(b!=0 && x>1) printf(" * %d^%d", prime[a], b);


                else if(m%prime[a]!=0){
                    a++;
                }
        }

        if(m>1) printf(" * %d^1",m);

        printf("\n");
    }
    return 0;
}

