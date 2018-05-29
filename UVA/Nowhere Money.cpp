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

long long fib[92];

void fcalc()
{
    fib[0] = fib[1] = 1;
    for(int i = 2; i<92; i++){
        fib[i] = fib[i-1] + fib[i-2];
        //printf("%lld\n", fib[i]);
    }
}

vector <LL> ai, ans;

int main(int argc, char const *argv[])
{
    //Read();
    //Write();
    fcalc();
    LL n;

    while(scanf("%lld", &n)==1){
        ai.clear();
        ans.clear();
        LL m = n;
        while(n){
            int x = upper_bound(fib, fib+92, n) - fib - 1;
            ai.pb(x);
            ans.pb(fib[x]);
            n -= fib[x];
        }
        printf("%lld\n", m);
        for(int i = 0; i<ai.size(); i++) printf("%lld ", ai[i]);
        printf("\n");
        for(int i = 0; i<ans.size(); i++) printf("%lld ", ans[i]);
        printf("\n\n");
    }

    return 0;
}