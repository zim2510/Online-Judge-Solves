#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define REP(i, a, b)      for(int i = a; a<=b; i++)
#define FOR(i, a, b)      for(int i = a; a<b; i++)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)			  ((x)*(x))

#define pb   push_back
#define LL   long long
#define ULL  unsigned long long
#define MAX  10000000

using namespace std;

int sum[5001][5001];
int input[5001], mx;
vector <int> org;

int dp(int sp, int cs)
{
	
	if(sp>=org.size()) return 0;
	if(sum[sp][cs]!=0) return sum[sp][cs];
	if(org[sp]>=0){
		sum[sp][cs] = org[sp] + dp(sp+1, cs);
	}
	else{
		if(cs) sum[sp][cs] = max(dp(sp+1, cs-1), org[sp]+dp(sp+1, cs));
		else sum[sp][cs] = max(0, org[sp]+dp(sp+1, cs));
	}
	if(mx<sum[sp][cs]) mx = sum[sp][cs]; 
	return sum[sp][cs];
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	int tc;
	scanf("%d", &tc);
	for(int i = 1; i<=tc; i++){
		memset(sum, 0, sizeof(sum));
		org.clear();
		int n, k;
		mx = 0;
		scanf("%d %d", &n, &k);
		for(int i = 0; i<n; i++) scanf("%d", &input[i]);

		int ts = 0;
		for(int i = 0; i<n; i++){
			if(input[i]<0){
				org.pb(ts);
				org.pb(input[i]);
				ts = 0;
			}
			else ts += input[i];
		}
		if(ts) org.pb(ts);
		dp(0, k);
		printf("Case %d: %d\n", i, mx);
	}

	return 0;
}