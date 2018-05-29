#include <bits/stdc++.h>
#define MAX 32001
using namespace std;

int prime[MAX], nprime[3432];
int sets[165][3];


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


void calc()
{
    int srt = 0, end = 32000, start = 0, s = 0;
    int si = lower_bound(nprime, nprime+3432, srt) - nprime;
    int ei = upper_bound(nprime, nprime+3432, end) - nprime;


    for(int i = si+2; i<ei; i++){
        if(!start && nprime[i]-nprime[i-1] == nprime[i-1]-nprime[i-2]){
            start = 1;
            sets[s][0] = nprime[i-2];
            sets[s][1] = nprime[i];
            sets[s][2] = nprime[i] - nprime[i-1];
            if(i==ei-1) s++;
        }
        else if(start){
            if(nprime[i]-nprime[i-1]==sets[s][2]){
                sets[s][1] = nprime[i];
                if(i==ei-1) s++;
            }
            else{
                start = 0;
                s++;
            }
        }
    }
}

int main()
{
    siv();
    calc();

    int srt, end;

    while(scanf("%d %d", &srt, &end)==2 && (srt || end)){
        if(end<srt) swap(end, srt);

        for(int i = 0; i<162; i++){
            if(srt<=sets[i][0] && end>=sets[i][1]){
                printf("%d", sets[i][0]);
                for(int x = sets[i][0] + sets[i][2]; x<=sets[i][1]; x+=sets[i][2]) printf(" %d", x);
                printf("\n");
            }
        }
    }
}
