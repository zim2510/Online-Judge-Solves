#include <stdio.h>

void btrack(int lvl, int n, int nt, int * track, int * mark, int * best, int * bdiff, int t){
	if(lvl==nt){
		int diff = n-t;
		if(diff<*bdiff){
			*bdiff = diff;
			for(int i = 0; i<nt; i++){
				best[i] = mark[i];
			}
		}
		return;
	}
	btrack(lvl+1, n, nt, track, mark, best, bdiff, t);
	if(t+track[lvl]<=n){
		mark[lvl] = 1;
		btrack(lvl+1, n, nt, track, mark, best, bdiff, t+track[lvl]);
		mark[lvl] = 0;
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, nt;
	while(scanf("%d %d", &n, &nt)==2){
		int track[nt] = {0}, mark[nt] = {0}, best[nt] = {0}, bdiff = (1<<31) - 1;
		for(int i = 0; i<nt; i++){
			scanf("%d", &track[i]);
		}
		btrack(0, n, nt, track, mark, best, &bdiff, 0);
		for(int i = 0; i<nt; i++){
			if(best[i]) printf("%d ", track[i]);
		} printf("sum:%d\n", n-bdiff);
	}
}