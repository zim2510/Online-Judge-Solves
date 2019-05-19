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

vector <ii> nodes;
vector <int> tree(300000);

void update(int node, int start, int end, int index, int value)
{
	if(start>index || end<index) return;
	if(start==end){
		tree[node] = max(tree[node], value);
		return;
	}

	update(node*2, start, (start+end)/2, index, value);
	update(node*2+1, (start+end)/2+1, end, index, value);

	tree[node] = max(tree[node*2], tree[node*2+1]);
}

int query(int node, int start, int end, int rstart, int rend)
{
	if(start>rend || end<rstart) return 0;
	if(start>=rstart && end<=rend) return tree[node];
	int x = query(node*2, start, (start+end)/2, rstart, rend);
	int y = query(node*2+1, (start+end)/2+1, end, rstart, rend);
	return max(x, y);
}

int main(int argc, char const *argv[])
{
	//Read();
    //Write();
    int n;
    scanf("%d", &n);
    vector <ii> q(n);
    for(int i = 0; i<n; i++){
    	sf("%d %d", &q[i].ff, &q[i].ss);
    }
    vector <ii> tmp = q;
    sort(tmp.begin(), tmp.end());
    map <ii, int> m;
    for(int i = 0; i<n; i++){
    	if(m[tmp[i]]==0) m[tmp[i]] = i+1;
    }

    for(int i = 0; i<n; i++){
    	int x = query(1, 1, n, 1, m[q[i]] - 1);
    	update(1, 1, n, m[q[i]], x+q[i].ss-q[i].ff+1);
    }

    cout<<query(1, 1, n, 1, n);
}
