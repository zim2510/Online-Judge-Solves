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

int tree[300005][3];
int pro[300005];

void buildtree(int node, int s, int e)
{
	if(s==e){
		tree[node][0] = 1;
		return;
	}
	buildtree(node*2, s, (s+e)/2);
	buildtree(node*2+1, (s+e)/2+1, e);
	tree[node][0] = tree[node*2][0] + tree[node*2+1][0];
	pro[node] = 0;
}

int query(int node, int s, int e, int rbegin, int rend)
{
	if(min(e, rend)<max(s, rbegin)) return 0;
	if(s>=rbegin && e<=rend) return tree[node][0];

	int mid = (s+e)/2;
	return query(node*2, s, mid, rbegin, rend) + query(node*2+1, mid+1, e, rbegin, rend);
}

void update(int node, int s, int e, int rbegin, int rend, int delta)
{
	if(min(e, rend)<max(s, rbegin)) return;


	if(s>=rbegin && e<=rend){
		pro[node] += 1;
		int carry = (-delta%3+3)%3;
		swap(tree[node][0], tree[node][carry]);
		swap(tree[node][carry], tree[node][(3-carry)%3]);
		return;
	}

	update(node*2, s, (s+e)/2, rbegin, rend, delta+pro[node]);
	update(node*2+1, (s+e)/2+1, e, rbegin, rend, delta+pro[node]);

	tree[node][0] = tree[node*2][0] + tree[node*2+1][0];
	tree[node][1] = tree[node*2][1] + tree[node*2+1][1];
	tree[node][2] = tree[node*2][2] + tree[node*2+1][2];
	//cout<<s<<" "<<e<<" "<<tree[node][0]<<" "<<tree[node][1]<<" "<<tree[node][2]<<endl;

}

int main(int argc, char const *argv[])
{
	Read();
    Write();
    
    int tc;
    scanf("%d", &tc);

    TC(i, 1, tc){
    	int n, q;
    	sf("%d %d", &n, &q);
    	buildtree(1, 1, n);
    	printf("Case %d:\n", i);
    	FOR(i, 0, q){
    		int qtype, s, e;
    		sf("%d %d %d", &qtype, &s, &e);
    		if(qtype) printf("%d\n", query(1, 1, n, s+1, e+1));
    		else update(1, 1, n, s+1, e+1, 0), pf("");
    	}

    }
}
