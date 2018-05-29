#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define REP(i, a, b)      for(int i = a; i<=b; i++)
#define FOR(i, a, b)      for(int i = a; i<b; i++)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)			  ((x)*(x))

#define pb   push_back
#define LL   long long
#define ULL  unsigned long long
#define MAX  10000000

using namespace std;

int main()
{
	Read();
	Write();
	int n, p, q, r;
	scanf("%d %d %d %d", &n, &p, &q, &r);
	vector <int> nums(n);
	vector <int> valsp;
	vector <int> valsq;
	vector <int> valsr;
	for(int i = 0; i<n; i++){
		scanf("%d", &nums[i]);
		valsp.pb(nums[i]*p);
		valsq.pb(nums[i]*q);
		valsr.pb(nums[i]*r);
	}
	sort(valsp.begin(), valsp.end());
	sort(valsq.begin(), valsq.end());
	sort(valsr.begin(), valsr.end());
	printf("%d %d %d\n", valsp[n-1], valsq[n-1], valsr[n-1]);
	printf("%d\n", valsp[n-1]+valsq[n-1]+valsr[n-1]);
	return 0;
}