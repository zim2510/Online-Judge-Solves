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

int BIT[100005];

void update(int index, int delta)
{
	while(index<100005){
		BIT[index] += delta;
		if(BIT[index]>=1000000007) BIT[index] %=  1000000007;
		index += (index & (-index));
	}
}

int query(int index)
{
	int sum = 0;
	while(index){
		sum += BIT[index];
		if(sum>=1000000007) sum %= 1000000007;
		index -= (index & (-index));
	}
	return sum%1000000007;
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
		MEM(BIT, 0);

		int n;
		sf("%d", &n);

		vector <int> nums(n);
		FOR(i, 0, n) sf("%d", &nums[i]);

		vector <int> X = nums;
		sort(all(X));

		map<int, int> m;

		FOR(i, 0, X.size()) if(m.find(X[i]) == m.end()) m[X[i]] = i+1;

		FOR(i, 0, n){
			int less = query(m[nums[i]]-1);
			update(m[nums[i]], less+1);
		}

		printf("Case %d: %d\n", i, query(n+5));
	}
}
