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

int value[] = {1, 5, 10, 50};
int dp[20][50000];
int M[20][1500];
int result[20];
int n;

void backtrack(int ci, int sofar)
{
	if(dp[ci][sofar]!=0) return;
	dp[ci][sofar] = 1;
	if(ci==n){
		if(M[n][sofar]==0) M[n][sofar] = 1, result[n]++;
		return;
	}

	for(int i = 0; i<4; i++){
		backtrack(ci+1, sofar+value[i]);
	}
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();

	TC(i, 1, 15){
		n = i;
		MEM(dp, 0);
		backtrack(0, 0);
	}

	int x;
	sf("%d", &x);
	if(x<=15) cout<<result[x]<<endl;
	else cout<<LL(result[15]) + LL(result[15] - result[14]) * LL(x-15)<<endl;
	
}
