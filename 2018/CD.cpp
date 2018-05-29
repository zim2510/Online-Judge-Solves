#include <bits/stdc++.h>

using namespace std;

int n, num[25], best, rem, ans[25], mark[25];

void backtrack(int pos, int rem)
{
	if(pos==n){
		if(rem<best){
			best = rem;
			for(int i = 0; i<n; i++) ans[i] = mark[i];
		}
		return;
	}
	backtrack(pos+1, rem);
	if(num[pos]<=rem){
		mark[pos] = 1;
		backtrack(pos+1, rem-num[pos]);
		mark[pos] = 0;
	}
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int mtime;
	while(scanf("%d", &mtime)==1){
		scanf("%d", &n);
		for(int i = 0; i<n; i++){
			scanf("%d", &num[i]);
		}
		best = INT_MAX;
		backtrack(0, mtime);
		for(int i = 0; i<n; i++){
			if(ans[i]) printf("%d ", num[i]);
		}
		printf("sum:%d\n", mtime-best);
	}

}