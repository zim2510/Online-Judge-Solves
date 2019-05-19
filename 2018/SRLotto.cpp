#include <stdio.h>
#include <malloc.h>

void backtrack(int depth, int n, int * nums, int taken, int * mark){
	if(depth==n){
		int printed = 0;
		if(taken==6) for(int i = 0; i<n; i++){
			if(mark[i]){
				printf("%d", nums[i]);
				printed++;
				if(printed==6) printf("\n");
				else printf(" ");
			}
		}
		return;
	}
	if(taken<6){
		mark[depth] = 1;
		backtrack(depth+1, n, nums, taken+1, mark);
		mark[depth] = 0;
	}
	backtrack(depth+1, n, nums, taken, mark);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int n, tc = 0;
	while(scanf("%d", &n) && n){
		if(tc++) printf("\n");
		int nums[n];
		for(int i = 0; i<n; i++){
			scanf("%d", &nums[i]);
		}
		int mark[n] = {0};
		backtrack(0, n, nums, 0, mark);
	}
}