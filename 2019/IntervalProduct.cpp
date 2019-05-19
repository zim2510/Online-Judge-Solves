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

bool check(int N,int pos)	{ return (bool)(N & (1<<pos)); }
int sset(int N,int pos)		{	return N=N | (1<<pos);	   }

int tree[300005];

void buildtree(int node, int l, int r)
{
	if(l==r){
		tree[node] = 1;
		return;
	}

	buildtree(node*2, l, (l+r)/2);
	buildtree(node*2+1, (l+r)/2+1, r);

	tree[node] = tree[node*2] * tree[node*2+1];
}

void update(int node, int l, int r, int i, int val)
{
	if(r<i || l>i) return;

	if(l==r){
		if(val>0) tree[node] = 1;
		else if(val<0) tree[node] = -1;
		else tree[node] = 0;
		return;
	}

	int mid = (l+r)/2;

	update(node*2, l, mid, i, val);
	update(node*2+1, mid+1, r, i, val);

	tree[node] = tree[node*2] * tree[node*2+1];

}

int query(int node, int l, int r, int rs, int re)
{
	if(max(l, rs)>min(r, re)) return 1;
	if(l>=rs && r<=re) return tree[node];

	int mid = (l+r)/2;

	return query(node*2, l, mid, rs, re) * query(node*2+1, mid+1, r, rs, re);
}

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	
	int n, k;
	while(sf("%d %d", &n, &k)==2){
		
		string out;
		buildtree(1, 1, n);
		
		TC(i, 1, n){
			int t;
			sf("%d", &t);
			update(1, 1, n, i, t);
		}

		TC(i, 1, k){
			char x;
			int y, z;
			sf(" %c %d %d", &x, &y, &z);
			if(x=='C'){
				update(1, 1, n, y, z);
			}
			else{
				int x = query(1, 1, n, y, z);
				if(x>0) out += '+';
				else if(x==0) out += '0';
				else out += '-';
			}
		}

		printf("%s\n", out.c_str());
	}
}
