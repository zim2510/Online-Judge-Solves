#include <bits/stdc++.h>
#define MAX 101

using namespace std;

int prime[101], nprime[25], freq[25];


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
    for(int i = 0; i<MAX; i++){
        if(!prime[i]) nprime[x++] = i;
    }
}

void calc(int hi)
{
    memset(freq, 0, sizeof(freq));

    int t = 0;

    for(int i = 2; i<=hi; i++){
        int n = i;
        int x = 0;
        while(n!=1){
            //printf("Looping with %d and %d\n", n, nprime[x]);
            if(n%nprime[x]==0){
                freq[x]++;
                t++;
                n = n/nprime[x];
            }
            else x++;
        }
    }

    for(int i = 0; i<25 && t; i++){
        printf(" %2d", freq[i]);
        t -= freq[i];
        if(t == 0) printf("\n");
        else if(i==14) printf("\n      ");
    }
}

int main()
{
    siv();
    int n;
    while(scanf("%d", &n) == 1 && n){
        printf("%3d! =", n);
        calc(n);
    }
    return 0;
}

