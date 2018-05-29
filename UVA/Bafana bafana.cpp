#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int tc;
	scanf("%d", &tc);
	for(int i = 1; i<=tc; i++){
		int n, k, p;
		scanf("%d %d %d", &n, &k, &p);
		int res = (p%n+k)%n;
		if(!res) res = n;
		printf("Case %d: %d\n", i, res);
	}
}