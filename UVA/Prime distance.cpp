#include <bits/stdc++.h>
#define MAX 46341
#define MEM(a, b) memset(a, b, sizeof(a));
using namespace std;

int mark[1000005];
bool prime[MAX+1];
int nprime[4792];

void siv()
{
    for(int i = 3; i*i<MAX; i+=2){
        if(!prime[i]){
            for(int x = i*i; x<MAX; x+=2*i) prime[x] = 1;
        }
    }
    nprime[0] = 2;
    int x = 1;
    for(int i = 3; i<MAX; i+=2){
        if(!prime[i]) nprime[x++] = i;
    }
}


void katakuti(int lo, int hi)
{
    MEM(mark, 0);
    if(lo<=1) mark[0] = 1;
    for(int i = 0; i<4792 && nprime[i]*nprime[i]<=hi; i++){
        int j;
        if(lo%nprime[i]==0) j = lo;
        else j = ceil(lo/nprime[i])*nprime[i];
        if(!prime[j] && (j%2 || j==2)) j += nprime[i];
        for(;j<=hi;j+=nprime[i]){
            mark[j-lo] = 1;
        }
    }
}


void chk(int lo, int hi)
{
    int mx = 0, mn = INT_MAX, p = -1;
    int mnnum[2], mxnum[2];

    for(int i = 0; i<(hi-lo+1); i++){
        if(!mark[i] && p<0){
            p = i;
        }
        else if(!mark[i]){
            if(i-p>mx){
                mx = i - p;
                mxnum[0] = lo + p;
                mxnum[1] = lo + i;
            }
            if(i-p<mn){
                mn = i - p;
                mnnum[0] = lo + p;
                mnnum[1] = lo + i;
            }
            p = i;
        }
    }

    if(!mx && mn == INT_MAX) printf("There are no adjacent primes.\n");
    else printf("%d,%d are closest, %d,%d are most distant.\n", mnnum[0], mnnum[1], mxnum[0], mxnum[1]);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    siv();
    int l, h;
    while(scanf("%d %d", &l, &h)==2){
        katakuti(l, h);
        chk(l, h);
    }
    return 0;
}
