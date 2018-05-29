#include <stdio.h>

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int tc;
	scanf("%d", &tc);
	for(int i = 1; i<=tc; i++){
		int c, b;
		scanf("%d %d", &c, &b);
		int r = -1, mx = -5;
		for(int i = 1; i<=b; i++){
			int time;
			scanf("%d", &time);
			if(time>mx){
				mx = time;
				r = i;
			}
		}
		printf("%d\n", r);
	}
}