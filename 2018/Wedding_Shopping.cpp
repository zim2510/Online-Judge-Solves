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

int money, items;
vector <vector <int> > cost;
int opt[500][500];

int dp(int item, int money)
{
	if(item==items) return money;
	if(opt[item][money]!=-1) return opt[item][money];

	opt[item][money] = INT_MAX;
	for(int i = 0; i<cost[item].size(); i++){
		int x = INT_MAX; 
		if(money>=cost[item][i]){ 
			x = dp(item+1, money-cost[item][i]);
			opt[item][money] = min(opt[item][money], x);
		}
	}
	return opt[item][money];

}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	int tc;
	scanf("%d", &tc);
	//cout<<tc<<endl;
	TC(i, 1, tc){
		scanf("%d %d ", &money, &items);
		//cout<<money<<" "<<items<<endl;
		cost.clear();
		cost.resize(items);
		for(int i = 0; i<items; i++){
			int x;
			scanf("%d", &x);
			cost[i].resize(x);
			for(int j = 0; j<x; j++) sf("%d", &cost[i][j]);
			// string s;
			// getline(cin, s);
			//cout<<"String "<<s<<endl;
			// stringstream str(s);
			// int t;
			// while(str>>t){
			// 	cost[i].pb(t);
			// }
		}
		//for(int i = 0; i<cost[0].size(); i++) cout<<cost[0][i]<<endl;
		MEM(opt, -1);
		int res = dp(0, money);
		if(res==INT_MAX) printf("no solution\n");
		else printf("%d\n", money-res);
	}
}
