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
	double p, q, r, s, t, u, res;
	while(scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u) == 6){
		double hi = 1, lo = 0, mid;
		for(int i = 0; i<50; i++){
			mid = (hi+lo)/2;
			res = p * exp(-mid) + q*sin(mid) + r*cos(mid) + s*tan(mid) + t*mid*mid + u;
			if(res>0) lo = mid;
			else hi = mid;
		}
		if(abs(res)<=0.00001) printf("%0.4lf\n", mid);
		else printf("No solution\n");
	}
}