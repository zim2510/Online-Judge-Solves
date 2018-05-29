#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define REP(i, a, b)      for(int i = a; a<=b; i++)
#define FOR(i, a, b)      for(int i = a; a<b; i++)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)            ((x)*(x))

#define pb   push_back
#define LL   long long
#define ULL  unsigned long long
#define MAX  10000001

using namespace std;

int prime[MAX], nprime[664589];
int nprimes = 0;
void siv()
{
    for(int i = 4; i<MAX; i+=2) prime[i] = 1;
    for(int i = 3; i*i<MAX; i+=2){
        if(!prime[i]) for(int x = i*i; x<MAX; x+=2*i) prime[x] = 1;
    }
    nprime[nprimes++] = 2;
    for(int i = 3; i<MAX; i+=2){
        if(!prime[i]) nprime[nprimes++] = i;
    }
}

int cnt[MAX];
int lmt = 0;
void precalc()
{
    for(int i = 2; i<MAX; i++){
        int x = i;
        for(int j = 0; nprime[j]*nprime[j]<=x; j++){
            while(x%nprime[j]==0){
                cnt[i]++;
                x /= nprime[j];
            }
        }
        if(x!=1) cnt[i]++;
        cnt[i] += cnt[i-1];
        if(cnt[i]>=MAX){
            lmt = i;
            break;
        }
    }
    cnt[0] = cnt[1] = 1;
}

int main(int argc, char const *argv[])
{
    //Read();
    //Write();
    siv();
    precalc();
    int tc;
    scanf("%d", &tc);
    for(int i = 1; i<=tc; i++){
        int n;
        scanf("%d", &n);
        int x = upper_bound(cnt, cnt+lmt, n) - cnt;
        printf("%d\n", x);
    }
    return 0;
}
