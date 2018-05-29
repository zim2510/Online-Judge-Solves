#include <bits/stdc++.h>
#define N 50000
int prime[50000], nprime[10000];
using namespace std;

void siv()
{
    prime[0] = prime[1] = 1;
    for(int i = 4; i<N; i+=2) prime[i] = 1;
    for(int i = 3; i*i<N; i+=2){
        if(!prime[i]){
            for(int x = i*i; x<N; x += 2*i){
                prime[x] = 1;
            }
        }
    }
    int x = 0;
    for(int i = 0; i<N; i++){
        if(!prime[i]) nprime[x++] = i;
    }
}


int main()
{
    siv();
    int n;
    while(scanf("%d", &n) && n){
        int c = 0;
        for(int i = 0; nprime[i]<=(n/2); i++){
            if(prime[n - nprime[i]] == 0) c++;
        }
        printf("%d\n", c);
    }
    return 0;
}

