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

vector <int> par(50, -1);

int Find(int node)
{
    if(par[node]==node) return node;
    par[node] = Find(par[node]);
    return par[node];
}

void Union(int node1, int node2)
{
    int x = Find(node1);
    int y = Find(node2);
    par[x] = y;
}


int main(int argc, char const *argv[])
{
    //Read();
    //Write();
    int tc;
    scanf("%d", &tc);
    getchar();
    getchar();

    while(tc--){
        int mx, q;
        scanf("%d %d", &mx, &q);
        getchar();
        for(int i = 0; i<=mx-'A'; i++) par[i] = i;
        while(true){
            char n1, n2;
            n1 = getchar();
            if(!isalpha(n1)) break;
            n2 = getchar();
            getchar();
            Union(n1-'A', n2-'A');
        }
        for(int i = 0; i<=mx-'A'; i++) Find(i);
        set <int> st;
        for(int i = 0; i<=mx-'A'; i++) st.insert(par[i]);
        cout<<st.size()<<endl;
        if(tc) cout<<endl;
    }
}
