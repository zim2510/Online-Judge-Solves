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
	int tc;
	scanf("%d", &tc);
	TC(i, 1, tc){
		int n, r, p, q;
		scanf("%d %d %d %d", &n, &r, &p, &q);
		int twos = 0, fives = 0, x = n;
		while(x){
			fives += x/5;
			x /= 5;
		}
		x = n;
		while(x){
			twos += x/2;
			x /= 2;
		}
		x = r;
		while(x){
			fives -= x/5;
			x /= 5;
		}
		x = r;
		while(x){
			twos -= x/2;
			x /= 2;
		}
		x = n-r;
		while(x){
			fives -= x/5;
			x /= 5;
		}
		x = n-r;
		while(x){
			twos -= x/2;
			x /= 2;
		}
		int xtwo = 0, xfive = 0;
		x = p;
		while(x%5==0){
			xfive++;
			x/=5;
		}
		x = p;
		while(x%2==0){
			xtwo++;
			x/=2;
		}
		twos += xtwo*q;
		fives += xfive*q;
		printf("Case %d: %d\n", i, min(twos, fives));
	}
}
