#include <stdio.h>

int main()
{
    freopen("in.txt", "r", stdin);
	int n, sum = 0, stones[25], i, best, cur, x, j;
	scanf("%d", &n);
	for(i = 0; i<n; i++){
		scanf("%d", &stones[i]);
		sum += stones[i];
	}
	best = sum;

	for(i = 1; i<(1<<n); i++){
		cur = 0;
		x = i;
		for(j = 0; j<n; j++){
			if(x&1==1){
				cur += stones[j];
				if(cur>sum/2) break;
				if((sum-cur)-cur<best){
                    best = (sum-cur)-cur;
				}
			}
			x = x>>1;
		}
	}
	printf("%d\n", best);
}
