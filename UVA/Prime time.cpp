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
#define MAX  10000000

using namespace std;

int prime[MAX], nprime[664589];
int numofprimes = 0;
int found[10001];
void siv()
{
    for(int i = 4; i<MAX; i+=2) prime[i] = 1;
    for(int i = 3; i*i<MAX; i+=2){
        if(!prime[i]) for(int x = i*i; x<MAX; x+=2*i) prime[x] = 1;
    }
    nprime[numofprimes++] = 2;
    for(int i = 3; i<MAX; i+=2){
        if(!prime[i]) nprime[numofprimes++] = i;
    }
    //printf("%d\n", numofprimes);
}


int check(LL x)
{
    //printf("%lld\n", x);
    if(x<MAX) return !prime[x];
    int lmt = sqrt(x);
    for(int i = 0; nprime[i]<=lmt; i++){
        if(x%nprime[i]==0) return 0;
    }
    return 1;
}

void isprime()
{
    for(int i = 0; i<40; i++) found[i] = i+1;
    for(int i = 40; i<=10000; i++){
        LL x = i*i + i + 41;
        found[i] = found[i-1] + check(x);
    }
}

int main(int argc, char const *argv[])
{
    //Read();
    //Write();
    siv();
    isprime();
    int sp, ep;
    while(scanf("%d %d", &sp, &ep)==2){
        int count;
        if(sp==0) count = found[ep];
        else count = found[ep] - found[sp-1];
        double result = (double)count/(ep+1-sp) + 0.0000001;
        //printf("C: %d %d\n", found[sp], found[ep]);
        printf("%0.2lf\n", result*100);
    }

    return 0;
}