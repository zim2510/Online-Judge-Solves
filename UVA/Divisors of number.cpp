#include <bits/stdc++.h>
#define MAX 10000000

using namespace std;

int prime[MAX], nprime[664580];

void siv()
{
    prime[0] = prime[1] = 1;
    for(int i = 4; i<=MAX; i+=2){
        prime[i] = 1;
    }
    for(int i = 3; i*i<MAX; i+=2){
        if(!prime[i]){
            for(int x = i*i; x<MAX; x+=2*i) prime[x] = 1;
        }
    }
    int x = 0;
    nprime[x++] = 2;
    for(int i = 3; i<MAX; i+=2){
        if(!prime[i]) nprime[x++] = i;
    }
    printf("%d\n", nprime[x-1]);
}

int main()
{
    siv();
    long long n;

    while(scanf("%lld", &n)==1 && n){
        long long x = sqrt(n);
        int zeros = 0;
        for(int i = 0; nprime[i]<x; i++){
            int num = n;
            int p = 1;
            printf("%d\n", zeros);
            while(num%nprime[i]==0){
                zeros+=p;
                p++;
                num /= nprime[i];
            }
            printf("%d\n", zeros);
            if(p!=1 && num!=1) {printf("%d %d %d\n", nprime[i], p, num); zeros++;}
        }
        printf("%d\n", zeros);
    }
}

