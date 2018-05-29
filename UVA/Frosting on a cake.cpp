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

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	int n;
    scanf("%d", &n);
    vector <LL> w(n), h(n);
    for(int i = 0; i<n; i++) scanf("%lld", &w[i]);
    for(int i = 0; i<n; i++) scanf("%lld", &h[i]);
    long long int fix[3] = {0, 0, 0};
    long long col[3] = {0, 0, 0};
    for(int i = 0; i<n; i++){
        fix[i%3] += h[0] * w[i];
    }
    for(int i = 0; i<n; i++){
        col[0] += (fix[(0+i*2)%3]*h[i])/h[0];
        col[1] += (fix[(1+i*2)%3]*h[i])/h[0];
        col[2] += (fix[(2+i*2)%3]*h[i])/h[0];
    }
    cout<<col[1]<<" "<<col[2]<<" "<<col[0]<<endl;
}