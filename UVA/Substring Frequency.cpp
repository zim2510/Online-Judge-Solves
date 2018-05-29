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

struct stringHash{
    string x;
    ULL base[1000010], hashed1[1000010], hashed2[1000010];
    void makeHash()
    {
        int sz = x.size();
        base[0] = 1;
        hashed1[0] = hashed2[0] = 0;
        for(int i = 1; i<=sz; i++){
            hashed1[i] = hashed1[i-1]*99571 + x[i-1];
            base[i] = base[i-1] * 99571;
        }
        for(int i = sz; i>0; i--){
            hashed2[i] = hashed2[i+1]*99571 + x[i-1];
        }
    }
    ULL getHash()
    {
        return hashed1[x.size()];
    }
    ULL getHash(int i, int j)
    {
        return hashed1[j] - hashed1[i-1]*base[j-i+1];
    }

    ULL getRHash(int i, int j)
    {
        return hashed2[i] - hashed2[j+1]*base[j-i+1];
    }
};
stringHash x, y;
int main(int argc, char const *argv[])
{
    //Read();
    int tc;
    cin>>tc;
    TC(i, 1, tc){
        cin>>x.x;
        cin>>y.x;
        x.makeHash();
        y.makeHash();
        int cnt = 0;
        for(int i = 1; i<=x.x.size();i++){
            cnt += x.getHash(i, i+y.x.size()-1) == y.getHash();
        }
        printf("Case %d: %d\n", i, cnt);
    }
    return 0;
}