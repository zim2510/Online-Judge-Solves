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
#define MOD				  10056

const int dx[] = { 0, -1,  0,  1,		 -1,  1,  1, -1,     -2, -2,  2,  2, -1, -1,  1,  1};
const int dy[] = {-1,  0,  1,  0,		  1,  1, -1, -1,     -1,  1, -1,  1, -2,  2, -2,  2};

using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

vector <int> nums;
vector <int> lis;
vector <int> mark;

void print(int x)
{
	vector <int> print(x+5);
	print[x-1] = lis[x-1];
	for(int i = nums.size()-1; i>=0; i--){
		if(nums[i]<print[mark[i]+1]) print[mark[i]] = nums[i];
	}
	pf("%d", print[0]);
	FOR(i, 1, x) pf(" %d", print[i]);
	printf("\n");
}

int LIS(int sz)
{
	lis.clear();
	mark.clear();

	FOR(i, 0, nums.size()){
		int x = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
		if(x==lis.size()){
			lis.pb(nums[i]);
			if(lis.size()==sz) break;
		}
		else lis[x] = nums[i];
		mark[i] = x;
	}

	if(lis.size()<sz) printf("Impossible\n");
	else print(sz);
}


int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif


	int tc;
	sf("%d", &tc);

	TC(i, 1, tc){
		int n, q;
		scanf("%d %d", &n, &q);
		nums.resize(n);
		mark.resize(n);
		printf("Case %d:\n", i);
		FOR(i, 0, n) sf("%d", &nums[i]);
		FOR(i, 0, q){
			int x;
			sf("%d", &x);
			LIS(x);
		}
	}
}
