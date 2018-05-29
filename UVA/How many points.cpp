#include <bits/stdc++.h>

using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);
	int tc;
	scanf("%d", &tc);
	for(int i = 1; i<=tc; i++){
		long long x1, y1, x2, y2;
		scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
		long long ans = __gcd(abs(x1-x2), abs(y1-y2)) + 1;
		printf("Case %d: %lld\n", i, ans);
	}
}