#include <bits/stdc++.h>

using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);
	int n, q, tc = 0;
	while(scanf("%d %d", &n, &q) && (n || q)){
		vector <int> marbles(n);
		for(int i = 0; i<n; i++) scanf("%d", &marbles[i]);
		sort(marbles.begin(), marbles.end());
		printf("CASE# %d:\n", ++tc);
		for(int i = 0; i<q; i++){
			int num;
			scanf("%d", &num);
			int r = lower_bound(marbles.begin(), marbles.end(), num) - marbles.begin();
			if(r<n && marbles[r]==num) printf("%d found at %d\n", num, r+1);
			else printf("%d not found\n", num);
		}
	}
}