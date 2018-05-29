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

bool cmp(ii x, ii y)
{
	if(x.ff!=y.ff) return x.ff>y.ff;
	else return x.ss<y.ss;
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	int l, g;
	while(scanf("%d %d", &l, &g) && l+g){
		vector <ii > range;
		vector <ii > sol;
		int possible = 0;
		for(int i = 0; i<g; i++){
			int sp, r;
			scanf("%d %d", &sp, &r);
			range.pb({sp+r, sp-r});
		}
		sort(range.begin(), range.end(), cmp);
		for(int i = 0; i<range.size(); i++) cout<<range[i].ff<<" "<<range[i].ss<<endl;
		int yfirst = range[0].ss + 1;
		for(int i = 0; i<range.size(); i++){
			if(range[i].ff<yfirst){
				possible = -1;
			}
			if(range[i].ss<yfirst){
				sol.pb(range[i]);
				yfirst = range[i].ss;
			}
		}
		if(possible) cout<<possible<<endl;
		else cout<<range.size()-sol.size()<<endl;
	}
}