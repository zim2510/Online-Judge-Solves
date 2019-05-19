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

vector <string> in[2];
int opt[105][105];
int nxt[105][105];
int mx = 0;

int dp(int i, int j)
{
	if(i>=in[0].size() || j>=in[1].size()) return 0;

	if(opt[i][j]!=-1) return opt[i][j];

	opt[i][j] = dp(i+1, j);
	if(dp(i, j+1)>opt[i][j]){
		opt[i][j] = dp(i, j+1);
		nxt[i][j] = 1;
	}
	if(in[0][i]==in[1][j]){
		if(opt[i][j]<1+dp(i+1, j+1)){
			opt[i][j] = 1 + dp(i+1, j+1);
			nxt[i][j] = 2;
		}
	}
	return opt[i][j];
}

void print(int i, int j, int count){
	if(count==mx) return;
	if(nxt[i][j]==-1) print(i+1, j, count);
	else if(nxt[i][j]==1) print(i, j+1, count);
	else{
		if(count) cout<<" ";
		cout<<in[0][i];
		print(i+1, j+1, count+1);
	}
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	string t;
	while(1){
		in[0].clear();
		in[1].clear();

		while(cin>>t){
			if(t=="#") break;
			in[0].pb(t);

		}

		while(cin>>t){
			if(t=="#") break;
			in[1].pb(t);
		}

		if(in[0].size()==0 && in[1].size()==0) break;

		MEM(opt, -1);
		MEM(nxt, -1);
		mx = dp(0, 0);
		print(0, 0, 0);
		cout<<endl;
	}
}
