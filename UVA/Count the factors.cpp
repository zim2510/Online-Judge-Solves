#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int prime[1000000], nprime[78498];

void siv()
{
    prime[0] = prime[1] = 1;
    for(int i = 4; i<MAX; i+=2) prime[i] = 1;
    for(int i = 3; i*i<MAX; i+=2){
        if(!prime[i]){
            for(int x = i*i; x<MAX; x+=2*i) prime[x] = 1;
        }
    }
    int x = 0;
    for(int i = 2; i<MAX; i++){
        if(!prime[i]) nprime[x++] = i;
    }
}

void calc(int x)
{
    int cnt = 0;
    int n = x;

    for(int i = 0; i<78498 && nprime[i]<=n && n>1; i++){
        if(!prime[n]){
            cnt++;
            n = 1;
        }
        else if(n%nprime[i]==0){
            cnt++;
            while(n%nprime[i]==0) n = n/nprime[i];
        }
    }
    printf("%d : %d\n", x, cnt);

}

int main()
{
    siv();
    int n;
    while(scanf("%d", &n) && n){
        calc(n);
    }
}
