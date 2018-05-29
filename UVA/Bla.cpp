#include <stdio.h>

int main()
{
	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);

	int at[n+1], st[n+1], ce[n+1], sl[n+1], wt[n+1], i, total = 0;
	for(i = 1; i<=n; i++) scanf("%d %d", &at[i], &st[i]);

	ce[1] = 0;
	for(i = 2; i<=n; i++) ce[i] = ce[i-1] + st[i-1];
	for(i = 1; i<=n; i++) sl[i] = st[i] + ce[i];
	for(i = 1; i<=n; i++) {wt[i] = ce[i] - at[i]; total += wt[i];}
	printf("St AT ST CE SL WT\n");
	for(int i = 1; i<=n; i++){
		printf("%2d %2d %2d %2d %2d %2d\n", i, at[i], st[i], ce[i], sl[i], wt[i]);
	}
	printf("Total Waiting Time: %d\n", total);


}