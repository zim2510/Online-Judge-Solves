#include <bits/stdc++.h>

using namespace std;

int prime[1000001];
int nprime[1000000];

void siv()
{
    prime[0] = prime[1] = 1;
    for(int i = 4; i<=1000001; i += 2) prime[i] = 1;
    for(int i = 3; i*i<1000001; i += 2){
        if(!prime[i]){
            //printf("%d\n", i);
            for(int x = i*i; x<1000001; x += 2*i){
                prime[x] = 1;
            }
        }
    }
    int c = 0;
    for(int i =3; i<1000001; i += 2){
        if(!prime[i]) nprime[c++] = i;
        //if(!prime[i]) printf("%d: %d\n", c-1, i);
    }
}

int main()
{
    siv();
    int x;
    printf("%d\n", prime[100007]);
    while(scanf("%d", &x) && x){
        for(int i = 0; nprime[i]<(x/2+1); i++){
            if(prime[x-nprime[i]] == 0){
                printf("%d = %d + %d\n", x, nprime[i], x - nprime[i]);
                break;;;;;
            }
        }
    }
}
