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

vector <LL> lookup;
void precalc()
{
	lookup.pb(1);
	while(lookup[lookup.size()-1]<=1000000000000000) lookup.pb(lookup[lookup.size()-1]*2);
	//FOR(i, 0, lookup.size()) cout<<lookup[i]<<endl;
}

LL calc(LL n)
{
	queue<LL> q;

	for(LL i = 1; i <= n; i++){
		q.push(i);
	}

	while(q.size() > 1){
		LL x = q.front();
		q.push(x);
		q.pop();
		q.pop();
	}

	return q.front();
}

int calc(int n)
{
	queue<int> q;
	for(int i = 1; i<=n; i++) q.push(i);
	while(q.size()>1){
		q.push(q.front());
		q.pop();
		q.pop();
	}
	return q.front();
}

int main()
{
	Read();
	Write();

	//precalc();


	int tc;
	scanf("%d", &tc);

	for(int i = 1; i<=tc; i++){
		int x, l, n;
		scanf("%d %d %d", &x, &l, &n);
		int alive = 0;
		for(int i = l; i<=n; i++){
			if(i<x) alive++;
			else if(calc(i)==x) alive++;
			cout<<calc(i)<<endl;
		}
		int g = __gcd(n, alive);
		alive /= g;
		n /= g;
		printf("Case %d: %d/%d\n", i, alive, (alive==0)?1:n);
	}
}
