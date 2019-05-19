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

int opt2[50][50];
int cnt = 0;

int dp(int x, int y, int mx, int my)
{
	if(x==mx || y==my) return 1;
	if(opt2[x][y]!=-1) return opt2[x][y];
	opt2[x][y] = dp(x+1, y, mx, my) + dp(x, y+1, mx, my);
	return opt2[x][y];
}

int opt[50][50][50][50];
string a, b;

int LCS(int x, int y, int lx, int ly)
{
	//cout<<lx<<" "<<ly<<endl;
	if(x==a.size() || y==b.size()){
		cnt += (a.size()-)
	}
	if(opt[x][y][lx][ly]!=-1) return opt[x][y][lx][ly];

	int ret = 0;
	
	if(a[x]==b[y]){
		MEM(opt2, -1);
		cnt += dp(1, 1, x-lx, y-ly);
		ret = 1 + LCS(x+1, y+1, x, y);
	}

	ret = max3(ret, LCS(x, y+1, lx, ly), LCS(x+1, y, lx, ly));

	return opt[x][y] = ret; 
}


int main(int argc, char const *argv[])
{
	Read();
    Write();
   	
   	int tc;
   	scanf("%d", &tc);

   	TC(i, 1, tc){
   		cin>>a>>b;
   		MEM(opt, -1);
   		cnt = 0;
   		int res = LCS(0, 0, -1, -1);
   		cout<<a.size()+b.size()-res<<" "<<cnt<<endl;
   		
   	}
}
