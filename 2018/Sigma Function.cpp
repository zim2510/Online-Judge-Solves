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


int tree[300000][3];
int stuck[300000];

int update(int node, int start, int end, int rbegin, int rend)
{
    if(rbegin>end || rfinish<start) return 0;
    else if(rbegin>=start && rfinish<=end){
        int zero = tree[node][0];
        int one = tree[node][1];
        int two = tree[node][2];
        tree[node][0] = two;
        tree[node][1] = zero;
        tree[node][2] = one;
        return tree[node];
    }
    else{
        tree[node][0] =
        tree[node][1] = 
        tree[node][2] = 
    }

}

int query(int node, int start, int end, int rbegin, int rfinish)
{
    if(rbegin>end || rfinish<start) return 0;
    if(rbegin>=start && rfinish<=end){
        return tree[node][]
    }
}

int main(int argc, char const *argv[])
{
    //Read();
    //Write();
    for(int i = 2; i*i<=n; i++){

    }
}