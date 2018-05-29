#include <bits/stdc++.h>
#define MAX 46341
using namespace std;

int mark[100005];
int prime[MAX+1];
int nprime[4792];

void siv()
{
    int lmt = sqrt(MAX);

    prime[0] = prime[1] = 1;

    int x = 0;

    nprime[x++] = 2;
    for(int i = 4; i<=MAX; i+=2) prime[i] = 1;
    for(int i = 3; i<=MAX; i+=2){
        if(!prime[i]){
            nprime[x++] = i;
            if(i<lmt){
                for(int j = i*i; j<=MAX; j+=2*i){
                    prime[j] = 1;
                }
            }
        }
    }
}

void katakuti(int lo, int hi)
{
    memset(mark, 0, sizeof(mark));

    if(lo<=1) mark[0] = 1;

    for(int i = 0; nprime[i]*nprime[i]<=hi && i<4792; i++){

        int j;
        if(lo%nprime[i]==0) j = lo;
        else j = ((lo/nprime[i]) + 1) * nprime[i];
        if(j == nprime[i]) j += nprime[i];

        for(; j<=hi && j>=lo; j+=nprime[i]){
            mark[j-lo] = 1;
        }
    }
}

void chk(int lo, int hi)
{
    for(int i = 0; i<(hi-lo+1); i++){
        if(!mark[i]) printf("%d\n", lo+i);
    }
}

int main()
{
    siv();
    int t;
    scanf("%d", &t);
    for(int i = 0; i<t; i++){
        if(i) printf("\n");
        int l, h;
        scanf("%d %d", &l, &h);
        katakuti(l, h);
        chk(l, h);
    }
    return 0;
}

