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

int lis[2005], lds[2005], w[2005];
int n;



int LIS(int pos)
{
    if(pos==n) return 0;
    if(lis[pos]!=-1) return lis[pos];
    lis[pos] = 1;
    for(int i = pos+1; i<n; i++){
    	if(w[i]>w[pos]) lis[pos] = max(lis[pos], 1+LIS(i));
    }
    return lis[pos];
}

int LDS(int pos)
{
	if(pos==n) return 0;
	if(lds[pos]!=-1) return lds[pos];
    lds[pos] = 1;
    for(int i = pos+1; i<n; i++){
    	if(w[i]<w[pos]) lds[pos] = max(lds[pos], 1+LDS(i));
    }
    return lds[pos];
}

int main(int argc, char const *argv[])
{
	//Read();
    //Write();;
    int tc;
    sf("%d", &tc);

    FOR(i, 0, tc){
    	sf("%d", &n);
    	FOR(i, 0, n) sf("%d", &w[i]);
    	MEM(lis, -1);
    	MEM(lds, -1);
    	FOR(i, 0, n) LIS(i);
    	FOR(i, 0, n) LDS(i);
    	int ans = 0;
    	FOR(i, 0, n){
    		ans = max(ans, lis[i]+lds[i]-1);
    	}
    	printf("%d\n", ans);
    }
}
