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

int input[100001], tree[300001];

void buildtree(int node, int start, int end)
{
	if(start==end){
		tree[node]= input[start];
		return;
	}
	buildtree(node*2, start, (start+end)/2);
	buildtree(node*2+1, (start+end)/2+1, end);

	tree[node] = tree[node*2] + tree[node*2+1];
}

int query(int node, int start, int end, int rstart, int rend)
{
	if(min(end, rend)<max(start, rstart)) return 0;
	if(start>=rstart && end<=rend) return tree[node];
	else return query(node*2, start, (start+end)/2, rstart, rend) + query(node*2+1, (start+end)/2+1, end, rstart, rend);
}

void update(int node, int start, int end, int index, int delta)
{
	if(start>index || end<index) return;
	else{
		tree[node] += delta;
		if(start!=end) update(node*2, start, (start+end)/2, index, delta);
		if(start!=end) update(node*2+1, (start+end)/2+1, end, index, delta);
	}
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	int tc;
	scanf("%d", &tc);
	TC(i, 1, tc){
		printf("Case %d:\n", i);
		int n, q;
		scanf("%d %d", &n, &q);
		for(int i = 1; i<=n; i++) scanf("%d", &input[i]);
		buildtree(1, 1, n);
		for(int i = 0; i<q; i++){
			int qtype;
			sf("%d", &qtype);
			if(qtype==1){
				int index;
				scanf("%d", &index);
				int delta = query(1, 1, n, index+1, index+1);
				printf("%d\n", delta);
				update(1, 1, n, index+1, -delta);
			}
			else if(qtype==2){
				int index, delta;
				scanf("%d %d", &index, &delta);
				update(1, 1, n, index+1, delta);
			}
			else{
				int s, e;
				scanf("%d %d", &s, &e);
				printf("%d\n", query(1, 1, n, s+1, e+1));
			}
		}
	}
}
