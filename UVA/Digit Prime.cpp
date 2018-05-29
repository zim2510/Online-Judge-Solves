#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int prime[MAX];
int nprime[78500];

int sum(int n)
{
    int sum = 0;
    while(n){
        sum += n%10;
        n = n/10;
    }
    if(prime[sum]) return 1;
    else return 0;
}

void siv()
{
    for(int i = 0; i<1000001; i++){
        prime[i] = 1;
    }

    prime[0] = prime[1] = 0;
    for(int i = 4; i<MAX; i+=2) prime[i] = 0;
    for(int i = 3; i*i<MAX; i+=2){
        if(prime[i]==1){
            for(int x = i*i; x<MAX; x+=2*i) prime[x] = 0;
        }
    }
    nprime[0] = 2;
    int x = 1;
    for(int i = 3; i<MAX; i++){
        if(prime[i]){
            nprime[x++] = i;
            prime[i] = prime[nprime[x-2]] + sum(i);
        }
    }
}


int main()
{
    siv();
    int tc;
    scanf("%d", &tc);
    for(int i = 0; i<tc; i++){
        int lo, hi, cnt = 0;
        scanf("%d %d", &lo, &hi);
        int sz = 78498;
        int s = lower_bound(nprime, nprime+sz, lo)-nprime-1;
        int e = upper_bound(nprime, nprime+sz, hi)-nprime-1;
        printf("%d\n", prime[nprime[e]] - prime[nprime[s]]);
    }
}
