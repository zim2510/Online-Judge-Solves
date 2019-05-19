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

int tree[3*200005];

void update(int node, int start, int end, int index, int value)
{
	if(index<start || index>end) return;
	if(start==end){
		tree[node] = value;
		return;
	}

	int mid = (start+end)/2;
	update(node*2, start, mid, index, value);
	update(node*2+1, mid+1, end, index, value);

	tree[node] = tree[node*2] + tree[node*2+1];
}

int query(int node, int start, int end, int rbegin, int rend)
{
	if(start>rend || end<rbegin) return 0;
	if(start>=rbegin && end<=rend) return tree[node];
	return query(node*2, start, (start+end)/2, rbegin, rend) + query(node*2+1, (start+end)/2+1, end, rbegin, rend);
}

int main(int argc, char const *argv[])
{
	//Read();
    //Write();
    int n;
    int c = 0;
    while(scanf("%d", &n) && n){
    	if(c++) printf("\n");
    	printf("Case %d:\n", c);
    	for(int i = 1; i<=n; i++){
    		int x;
    		scanf("%d", &x);
    		update(1, 1, n, i, x);
    	}
    	string x;
    	while(cin>>x){
    		if(x=="END") break;
    		int a, b;
    		scanf("%d %d", &a, &b);
    		if(x=="M") printf("%d\n", query(1, 1, n, a, b));
    		else update(1, 1, n, a, b);
    	}
    }
}
