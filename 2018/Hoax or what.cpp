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

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	multiset <int> x;
	unordered_map<int, int> m;

	int n;
	while(scanf("%d", &n) && n){
		long long int result = 0;
		x.clear(), m.clear();
		FOR(i, 0, n){
			//printf("\n\n\nDay %d: ", i);
			int z, begin, end;
			scanf("%d", &z);
			FOR(i, 0, z){
				int t;
				scanf("%d", &t);
				x.insert(t);
			}

			begin = *(x.begin());
			m[begin]++;
			if(m[begin]==x.count(begin)) x.erase(begin), m[begin] = 0;
			
			end = *(x.rbegin());
			m[end]++;
			if(m[end]==x.count(end)) x.erase(end), m[end] = 0;

			result += (end-begin);
		}

		printf("%lld\n", result);
	}
	
}