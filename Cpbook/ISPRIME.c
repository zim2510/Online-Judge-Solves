#include <stdio.h>

int isprime(unsigned long long int input);

int main()
{
    unsigned long long int  input;
    int i;

    scanf("%d", &i);
    while(i--){
        scanf("%lld", &input);
        getchar();
        if(1==isprime(input)){
            printf("%lld is a prime\n",input);
        }
        else printf("%lld is not a prime\n",input);
    }
}

int isprime(unsigned long long int input)
{
    unsigned long int prime[1000]={0};
    unsigned int i,j,n,root;

    if(input==2) return 1;
    else if(input==0||input==1||input%2==0) return 0;

    root=sqrt(input);

    prime[0]=2;

    for(n=3,i=j=0;n<=root && prime[j]<=root && i<1000;){
        if(n%prime[j]!=0 && j==i){
            prime[++i]=n;
            if(input%n==0) return 0;
            n++;
            j=0;
        }
        else if(n%prime[j]!=0){
            j++;
        }
        else if(n%prime[j]==0){
            n++;
            j=0;
        }
    }

    return 1;
}

