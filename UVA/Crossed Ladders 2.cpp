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
	Read();
	Write();
	int tc;
	scanf("%d", &tc);

	TC(i, 1, tc){
		double x, y, h;
		scanf("%lf %lf %lf", &x, &y, &h);
		double lo = 0, hi = min(x, y), ans;
		while(true){
			double mid = (lo+hi)/2;
			
			double h1 = x*sin(acos(mid/x));
			double ratio1 = h1/h;
			double obase = mid/ratio1;
			double area1 = (.5*h1*(mid-obase));
			
			double h2 = y*sin(acos(mid/y));
			double ratio2 = h2/h;
			double tbase = mid/ratio2;
			double area2 = (.5*h2*(mid-tbase));

			double tri = .5*mid*h;

			double total1 = (.5*mid*h1) + (.5*mid*h2) - tri;
			double total2 = area1 + area2 + tri;
			cout<<total1<<" "<<total2<<" "<<mid<<endl;
			if(abs(total1-total2)<=0.0000001){
				ans = mid;
				break;
			}
			else if(total1<total2){
				hi = mid;
			}
			else lo = mid;
		}
		printf("Case %d: %lf\n", i, ans);
	}
}