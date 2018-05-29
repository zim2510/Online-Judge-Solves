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
 
const int dx[] = { 0, -1,  0,  1,        -1,  1,  1, -1,     -2, -2,  2,  2, -1, -1,  1,  1};
const int dy[] = {-1,  0,  1,  0,         1,  1, -1, -1,     -1,  1, -1,  1, -2,  2, -2,  2};
 
using namespace std;
 
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;
 
inline LL ssum(LL n)
{
    return (n*(n-1))/2;
}
 
double bigmod(double n, LL p)
{
    if(p==0) return 1.0;
    if(p%2) return n*bigmod(n, p-1);
    double x = bigmod(n, p/2);
    return x*x;
}
 
int main(int argc, char const *argv[])
{
    Read();
    Write();
    int tc;
    scanf("%d", &tc);
    TC(i, 1, tc){
        int hi, lo = 1, mid, ans;
        scanf("%d", &hi);
        ans = hi;
        double base = double (hi-1)/hi;
        while(hi>=lo){
            mid = (hi+lo)/2;
            double x = bigmod(base, ssum(mid+1));
            cout<<lo<<" "<<hi<<" "<<mid<<" "<<ssum(mid+1)<<" "<<x<<endl;
            if(x>.50) lo = mid+1;
            else{
                if(mid<ans) ans = mid;
                hi = mid-1;
            }
        }
        printf("Case %d: %d\n", i, ans);
    }
}