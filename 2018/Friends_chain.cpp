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

vector <vector<int>> graph;
vector <int> clr;
vector <int> opt;

int best = 0, bnode = 0;

int dfs(int node, int depth)
{
    if(clr[node]) return 0;
    if(depth>best){
        best = depth;
        bnode = node;
    }
    clr[node] = 1;
    for(int i = 0; i<graph[node].size(); i++){
        dfs(graph[node][i], depth+1);
    }
}

int main(int argc, char const *argv[])
{
    Read();
    Write();

    int n;
    while(sf("%d", &n) && n){
        graph.clear();
        graph.resize(n+1);
        map <string, int> m;
        int id = 1;
        FOR(i, 0, n){
            string tmp;
            cin>>tmp;
            m[tmp] = id++;
        }

        int k;
        sf("%d", &k);
        FOR(i, 0, k){
            string t1, t2;
            cin>>t1>>t2;
            graph[m[t1]].pb(m[t2]);
            graph[m[t2]].pb(m[t1]);
        }

        int res = 0;
        clr.clear();
        clr.resize(n+1);
        dfs(1, 0);
        clr.clear();
        clr.resize(n+1);
        dfs(bnode, 0);
        cout<<best<<endl;
    }
    return 0;
}