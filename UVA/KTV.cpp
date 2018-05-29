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
#define sz(a) 			  int((a).size())
#define all(c)            (c).begin(),(c).end()
#define tr(c,i)           for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)      ((c).find(x) != (c).end())
#define cpresent(c,x)     (find(all(c),x) != (c).end())
#define pb                push_back
#define MAX               1000000000

using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

int a[81], b[81], c[81], p[81];
int mark[10];
int n, mx;

void btrack(int dep, int pts)
{
	if(dep==3){
		if(pts>mx) mx = pts;
		return;
	}
	for(int i = 0; i<n; i++){
		if(!mark[a[i]] && !mark[b[i]] && !mark[c[i]]){
			mark[a[i]] = mark[b[i]] = mark[c[i]] = 1;
			btrack(dep+1, pts+p[i]);
			mark[a[i]] = mark[b[i]] = mark[c[i]] = 0;
		}
	}
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	int tc = 0;
	while(scanf("%d", &n) && n){
		for(int i = 0; i<n; i++) scanf("%d %d %d %d", &a[i], &b[i], &c[i], &p[i]);
		mx = -1;
		btrack(0, 0);
		printf("Case %d: %d\n", ++tc, mx);
	}
}
