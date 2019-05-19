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
#define sf                scanf
#define pf                printf

const int dx[] = { 0, -1,  0,  1,        -1,  1,  1, -1,     -2, -2,  2,  2, -1, -1,  1,  1};
const int dy[] = {-1,  0,  1,  0,         1,  1, -1, -1,     -1,  1, -1,  1, -2,  2, -2,  2};

using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

class disset{
    public:
    std::vector <int> par;
    disset(int n)
    {
        par.resize(n);
        for(int i = 0; i<n; i++) par[i] = i;
    }

    int Find(int node)
    {
        if(par[node]==node) return node;
        par[node] = Find(par[node]);
        return par[node];
    };

    void Union(int node1, int node2)
    {
        int x = Find(node1);
        int y = Find(node2);
        par[x] = y;
    }
};

vector <double> tree;

void findmintree(vector<pair<int, ii>> distance)
{
    disset D(distance.size()+1);
    for(int i = 0; i<distance.size(); i++){
        //cout<<distance[i].ss.ff<<" "<<distance[i].ss.ss<<endl;
        if(D.Find(distance[i].ss.ff)==D.Find(distance[i].ss.ss)) continue;
        //printf("Taking in\n");
        tree.pb(sqrt((double)distance[i].ff));
        D.Union(distance[i].ss.ff, distance[i].ss.ss);
    }
}

int main(int argc, char const *argv[])
{
    //Read();
    //Write();
    int tc;
    scanf("%d", &tc);
    TC(i, 1, tc){
        int s, x;
        sf("%d %d", &s, &x);
        vector <ii> p(x);
        for(int i = 0; i<x; i++){
            sf("%d %d", &p[i].ff, &p[i].ss);
        }
        vector <pair<int, ii> > distance; 
        for(int i = 0; i<x; i++){
            for(int j = i+1; j<x; j++){
                int dis = SQR(p[i].ff-p[j].ff)+SQR(p[i].ss-p[j].ss);
                distance.pb({dis, {i, j}});
            }
        }
        sort(distance.begin(), distance.end());
        findmintree(distance);
        printf("%0.2lf\n", tree[tree.size()-1-(s-1)]);
    }
}
