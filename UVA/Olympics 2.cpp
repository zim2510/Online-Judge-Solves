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
		int lr, wr;
		scanf("%d : %d", &lr, &wr);
		double lo = 0, hi = 1000, mid, ans;
		while(hi-lo>0.0000001){
			mid = (lo+hi)/2;
			double l = mid*lr;
			double w = mid*wr;
			double r = (sqrt(l*l + w*w))/2;
			double t = acos((2*r*r-w*w)/(2*r*r));
			double p = 2*(r*t+l);
			if(abs(400-p)<=0.000001){
				ans = mid;
				break;
			}
			else if(p<400) lo = mid;
			else hi = mid;
		}
		printf("Case %d: %0.8f %0.8f\n", i, ans*lr, ans*wr);
	}
}
