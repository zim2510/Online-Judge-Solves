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

int in[100005], tree[400005];

void buildtree(int node, int s, int e)
{
	if(s==e){
		tree[node] = in[s];
		return;
	}
	buildtree(node*2, s, (s+e)/2);
	buildtree(node*2+1, (s+e)/2+1, e);
	tree[node] = min(tree[node*2], tree[node*2+1]);
}

void update(int node, int s, int e, int index, int val)
{
	if(e<index || s>index) return;
	if(s == e) { tree[node] = val; return; }
	update(node*2, s, (s+e)/2, index, val);
	update(node*2+1, (s+e)/2+1, e, index, val);
	tree[node] = min(tree[node*2], tree[node*2+1]);
}

int query(int node, int s, int e, int rs, int re)
{
	if(max(s,rs)>min(e, re)) return INT_MAX;
	if(s>=rs && e<=re) return tree[node];
	return min(query(node*2, s, (s+e)/2, rs, re), query(node*2+1, (s+e)/2+1, e, rs, re));
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	int n, q;
	scanf("%d %d", &n, &q);
	for(int i = 1; i<=n; i++) scanf("%d", &in[i]);
	getchar();
	buildtree(1, 1, n);
	for(int i = 0; i<q; i++){
		char str[10];
		scanf("%[^(]", str);
		getchar();
		vector <int> qentry;
		while(true){
			int n;
			char ch;
			scanf("%d%c", &n, &ch);
			qentry.pb(n);
			if(ch==')') break;
		}
		getchar();
		if(str[0]=='q'){
			printf("%d\n", query(1, 1, n, qentry[0], qentry[1]));
		}
		else{
			int temp = in[qentry[0]];
			for(int i = 0; i<qentry.size(); i++){
				if(i==qentry.size()-1){
					update(1, 1, n, qentry[i], temp);
					in[qentry[i]] = temp;
				}
				else{
					update(1, 1, n, qentry[i], in[qentry[i+1]]);
					in[qentry[i]] = in[qentry[i+1]];
				}
			}
			//cout<<endl;
		}
	}
	return 0;
}