#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out1.txt", "w", stdout)
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
#define MAX               10000
#define ff                first
#define ss                second
#define sf                   scanf
#define pf                   printf
#define MOD                  1000000007

const int dx[] = { 0, -1,  0,  1,         -1,  1,  1, -1,     -2, -2,  2,  2, -1, -1,  1,  1};
const int dy[] = {-1,  0,  1,  0,          1,  1, -1, -1,     -1,  1, -1,  1, -2,  2, -2,  2};

using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

bool check(int N,int pos)    { return (bool)(N & (1<<pos)); }
int sset(int N,int pos)        {    return N=N | (1<<pos);       }

int main(int argc, char const *argv[])
{
    Read();
    Write();



    for(int i = 1; i<=1; i++){
        LL g, l;
        sf("%lld %lld", &g, &l);

        LL seed = l/g;
        int cnt = 0;

        for(int x = 2; x*x<=seed; x++){
            if(seed%x==0){
                cnt++;
                while(seed%x==0) seed /= x;
            }
        }

        if(seed!=1) seed = 1, cnt++;
        printf("Case %d: %lld\n", i, (1LL<<max(0, cnt-1)));
    }
    return 0;
}