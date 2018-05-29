#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define TC(i, a, b)       for(int i = a; i<=b; i++)
#define FOR(i, a, b)      for(int i = a; i<b; i++)
#define ROF(i, a, b)      for(int i = a; i>=b; i--)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)			  ((x)*(x))
#define valid(x, s, e) 	  (x>=s && x<=e)
#define sz(a) 			  int((a).size())
#define all(c)            (c).begin(),(c).end()
#define tr(c,i)           for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)      ((c).find(x) != (c).end())
#define cpresent(c,x)     (find(all(c),x) != (c).end())
#define pb                push_back
#define MAX               1000000000
#define ff 				  first
#define ss				  second
#define eps   			  1e-9
using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

int main(int argc, char const *argv[])
{
	Read();
	int tc;
	scanf("%d", &tc);
	TC(i, 1, tc){
		double l, t, coeff;
		scanf("%lf %lf %lf", &l, &t, &coeff);
		double nl = (1+coeff*t)*l;

		double lo = l/2, hi = 1000000, ans = 0;
        cout<<i<<endl;
		while(nl!=l){
			double r = (lo+hi)/2;
			double th = 2*asin((l)/(2*r));
			if(abs(r*th-nl)<eps){
				ans = r - r*cos(th/2);
				break;
			}
			else if(r*th<nl) hi = r;
			else lo = r;
		}
		printf("Case %d: %0.10lf\n", i, ans);
	}
}
