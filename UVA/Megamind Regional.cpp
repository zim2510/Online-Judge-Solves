#include <bits/stdc++.h>
 
#define Read() freopen("in.txt", "r", stdin)
#define Write() freopen("out.txt", "w", stdout)
#define min3(a, b, c) min(a, min(b,c))
#define max3(a, b, c) max(a, max(b,c))
#define TC(i, a, b) for(int i = a; i<=b; i++)
#define FOR(i, a, b) for(int i = 0; i<b; i++)
#define MEM(a, x) memset(a, x, sizeof(a))
#define SQR(x) ((x)*(x))
#define valid(x, s, e) (x>=s && x<=e)
#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define MAX 10e9
#define ff first
#define ss second
#define sf scanf
#define pf printf
 
using namespace std;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long LL;
typedef unsigned long long ULL;
 
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc;
    sf("%d", &tc);
    TC(i, 1, tc){
        LL init, pwr, gulis, regen;
        scanf("%lld %lld %lld %lld", &init, &pwr, &gulis, &regen);
        printf("Case %d: ", i);
        LL fullround = pwr*gulis - regen;
        if(fullround<=0){
            if(pwr*gulis<init) printf("-1\n");
            else{
                LL ans = init/pwr;
                if(init%pwr) ans++;
                printf("%lld\n", ans);
            }
        }
        else{
            cout<<" ";
            cout<<init-pwr*gulis<<endl;
            cout<<fullround<<endl;
            LL n = (init - pwr*gulis)/(fullround);
            if((init - pwr*gulis)%fullround) n++;
            LL guli = n*gulis;
            init -= (n*fullround);
            guli += (init/pwr);
            if(init%pwr) guli++;
            printf("%lld\n", guli);
        }
 
    }
    return 0;
 
 
}