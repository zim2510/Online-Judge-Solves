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

using namespace std;


typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

int tree[300000];
char in[100001];
void buildtree(int node, int s, int e)
{
	if(s==e){
		tree[node] = 0;
		return;
	}
	buildtree(node*2, s, (s+e)/2);
	buildtree(node*2+1, (s+e)/2+1, e);
	tree[node] = 0;
}

void update(int node, int s, int e, int rs, int re)
{
	if(max(s, rs)>min(e, re)) return;
	if(s>=rs && e<=re){
		tree[node]++;
		return;
	}
	update(node*2, s, (s+e)/2, rs, re);
	update(node*2+1, (s+e)/2+1, e, rs, re);
}

int query(int node, int s, int e, int x)
{
	if(s>x || e<x) return 0;
	if(s==x && e==x){
		return tree[node];
	}
	return tree[node] + query(node*2, s, (s+e)/2, x) + query(node*2+1, (s+e)/2+1, e, x);
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	int tc;
	scanf("%d", &tc);
	TC(i, 1, tc){
		scanf(" %s", in);
		int n = strlen(in);
		buildtree(1, 0, n-1);
		int q;
		sf("%d", &q);
		pf("Case %d:\n", i);
		FOR(i, 0, q){
			char qtype;
			scanf(" %c", &qtype);
			if(qtype=='I'){
				int s, e;
				scanf("%d %d", &s, &e);
				update(1, 0, n-1, s-1, e-1);
			}
			else{
				int x;
				scanf("%d", &x);
				int out = in[x-1] - '0';
				x = query(1, 0, n-1, x-1);
				if(x%2==0) printf("%d\n", out);
				else printf("%d\n", !out);
			}
		}
	}
}