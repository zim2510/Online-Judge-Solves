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
#define MAX  100000

using namespace std;

int prime[MAX], nprime[10000];
int nprimes;
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

int sodigits(int n)
{
    int s = 0;
    while(n){
        s += (n%10);
        n /= 10;
    }
    return s;
}


int smith(int n, int sn)
{
    int s = 0;
    for(int i = 0; nprime[i]*nprime[i]<=n; i++){
        while(n%nprime[i]==0){
            n /= nprime[i];
            s += sodigits(nprime[i]);
        }
    }
    if(n!=1) s += sodigits(n);
    if(sn==s){
        return n;
    }
    else return 0;
}

int main(int argc, char const *argv[])
{
    //Read();
    //Write();
    siv();
    int tc;
    scanf("%d", &tc);
    for(int i = 1; i<=tc; i++){
        int n;
        scanf("%d", &n);
        for(int i = n+1; ;i++){
        	int r = smith(i, sodigits(i));
            if(r && r!=i){
                printf("%d\n", i);
                break;
            }
        }
    }


    return 0;
}
