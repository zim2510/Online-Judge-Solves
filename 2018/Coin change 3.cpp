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
#define sf             	  scanf
#define pf 	              printf

const int dx[] = { 0, -1,  0,  1,		 -1,  1,  1, -1,     -2, -2,  2,  2, -1, -1,  1,  1};
const int dy[] = {-1,  0,  1,  0,		  1,  1, -1, -1,     -1,  1, -1,  1, -2,  2, -2,  2};

using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

int n;
int opt[100005][105];
int coin[105], use[105];

int pos(int num, int used)
{
    if(num==0) return 1;
    if(num<0) return 0;
    if(ci==n) return 0;

    if(opt[num][ci]!=-1) return opt[num][ci];
    opt[num][ci] = pos(num, ci+1) + pos(num-coin[ci], ci+1);
    return opt[num][ci]>0;

}


int main(int argc, char const *argv[])
{
	Read();
    Write();;
    int tc;
    sf("%d", &tc);

    TC(i, 1, tc){
    	int mx;
        scanf("%d %d", &n, &mx);
        FOR(i, 0, n) scanf("%d", &coin[i]);
        FOR(i, 0, n) scanf("%d", &use[i]);
        sort(coin, coin+n);
        
        int ans = 0;
        MEM(opt, -1);
        pos(10, 0);
        // for(int i = mx; i>=1; i--){
        //     ans += pos(i, 0);
        // }
        printf("Case %d: %d\n", i, ans);
    }
}
