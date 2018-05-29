#include <bits/stdc++.h>
 
#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define TC(i, a, b)       for(int i = a; i<=b; i++)
#define FOR(i, a, b)      for(int i = a; i<b; i++)
#define ROF(i, a, b)      for(int i = a; i>=b; i--)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)            ((x)*(x))
#define valid(x, s, e)    (x>=s && x<=e)
#define sz(a)             int((a).size())
#define all(c)            (c).begin(),(c).end()
#define tr(c,i)           for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)      ((c).find(x) != (c).end())
#define cpresent(c,x)     (find(all(c),x) != (c).end())
#define pb                push_back
#define MAX               1000000000
#define ff                first
#define ss                second
#define sf                scanf
#define pf                printf
 
using namespace std;
 
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;
 
LL bigmod(ULL n, LL p)
{
    if(!p) return 1;
    if(p&1) return (n*bigmod(n, p-1))%MAX;
    LL x = bigmod(n, p>>1);
    return (x*x)%MAX;
}
 
int main(int argc, char const *argv[])
{
    //Read();
    //Write();
    int tc;
    scanf("%d", &tc);
    for(int i = 1; i<=tc; i++){
        int r, c, clr, blk;
        scanf("%d %d %d %d", &r, &c, &clr, &blk);
        map < pair <int, int>, int> mp;
        vector < pair<int, int> > blocked;
        LL ok = c, less = (LL)(r-1)*c, total = r*c;
        for(int j = 0; j<blk; j++){
            int x, y;
            scanf("%d %d", &x, &y);
            blocked.pb({x, y});
            mp[{x, y}] = 1;
        }
        for(int k = 0; k<blocked.size(); k++){
            if(blocked[k].ff==1){
                ok--;
            }
            else{
                less--;
            }
            if(blocked[k].ff+1<=r && mp.find({blocked[k].ff+1, blocked[k].ss})==mp.end()){
                less--;
                ok++;
            }
        }
        LL r1, r2;
        r1 = bigmod(clr, ok);
        r2 = bigmod(clr-1, less);
        LL result = (r1*r2)%1000000000;
        printf("Case %d: %lld\n", i, result);
    }
}