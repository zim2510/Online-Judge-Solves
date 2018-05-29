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

int main(int argc, char const *argv[])
{
	Read();
	Write();
	int tc;
	scanf("%d", &tc);
	LL nums[100005];
	LL sums[100005];

	for(int i = 1; i<=tc; i++){
		int k, c, n;
		scanf("%d %d %d %lld", &k, &c, &n, &nums[0]);
		for(int i = 1; i<n; i++) nums[i] = (k*nums[i-1]+c)%1000007;
		sort(nums, nums+n);
		sums[0] = nums[0];
		for(int i = 1; i<n; i++) sums[i] = sums[i-1] + nums[i];
		LL diff = 0;
		for(int i = 0; i<n; i++){
			diff += (sums[n-1] - sums[i]) - (ULL)(n-1-i)*(nums[i]);
		}
		printf("Case %d: %lld\n", i, diff);
	}
}