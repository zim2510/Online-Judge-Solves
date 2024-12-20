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

struct disset
{
    vector <int> par;
    disset(int n){
        par.resize(n+1);
        for(int i = 0; i<=n; i++) par[i] = i;
    }
    int Find(int node){
        if(par[node]==node) return node;
        par[node] = Find(par[node]);
        return par[node];
    }
    void Union(int node1, int node2){
        int x = Find(node1);
        int y = Find(node2);
        //cout<<"X: "<<x<<" Y: "<<y<<endl;
        par[x] = y;
        //cout<<"Connecting "<<node1<<" and "<<node2<<endl;
    }
};

bool dis(double x1, double x2, double y1, double y2, double r1, double r2){
    //cout<<"B "<<x1<<" "<<y1<<" "<<r1<<" "<<x2<<" "<<y2<<" "<<r2<<endl;
    double d = SQR(x1-x2) + SQR(y1-y2);
    double mx = SQR(r1 + r2);
    double mn = SQR(max(r1, r2) - min(r1, r2));
    cout<<d<<" "<<mx<<" "<<mn<<endl;
    return d<=mx && d>=mn;
}

int main(int argc, char const *argv[])
{
    Read();
    Write();
    int n;
    while(scanf("%d", &n) && n>0){
        disset x(n);
        vector <vector <double> > points(1, vector<double>(3));
        for(int i = 1; i<=n; i++){
            double x, y, r;
            scanf("%lf %lf %lf", &x, &y, &r);
            points.pb({x, y, r});
        }
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(dis(points[i][0], points[j][0], points[i][1], points[j][1], points[i][2], points[j][2])){
                    x.Union(i, j);
                }
                cout<<endl;
            }
        }
        map<int, int> cnt;
        int mx = 0;
        for(int i = 1; i<=n; i++){
            //cout<<x.Find(i);
            cnt[x.Find(i)]++;
            cout<<x.Find(i)<<endl;
            if(cnt[x.Find(i)]>mx) mx = cnt[x.Find(i)];
        }
        cout<<"The largest component contains "<<mx<<" rings."<<endl;
    }
}