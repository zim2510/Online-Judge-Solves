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

int path[30] = {0};
int opt[1<<25][3];
ii init;
int n;

vector <ii> coord;

int distance(ii x, ii y)
{
	return SQR(x.ff-y.ff) + SQR(x.ss-y.ss);
}

int dp(int state, int pos, int cnt)
{
	if(opt[state][pos]!=-1) return opt[state][pos];
	if(state==(1<<25)) return 0;
	if(pos==0){
		int o = INT_MAX;
		FOR(i, 0, n){
			if(!(state&(1<<i)))int o = min(o, distance(coord[i], init) + dp(state|(1<<i), i, 1));
		}
		return opt[state][pos] = o;
	}

	else if(pos==1){
		int o = INT_MAX;
		FOR(i, 0, n){
			if(!(state&(1<<i))) o = min(o, distance(coord[i], coord[pos]) + dp(state|(1<<i), i, 2));
		}
		opt[state][pos] = min(o,  distance(coord[pos], init) + dp(state, 0, 0));
		return opt[state][pos];
	}

	else if(pos==2){
		opt[state][pos] = distance(coord[pos], init) + dp(state, 0, 0);
		return opt[state][pos];
	}
}

int main(int argc, char const *argv[])
{
	Read();
	Write();

	scanf("%d %d", &init.ff, &init.ss);
	scanf("%d", &n);
	coord.resize(n);
	FOR(i, 0, n){
		scanf("%d %d", &coord[i].ff, &coord[i].ss);
	}

	cout<<dp(0, 0)<<endl;
}