#include <stdio.h>
#include <math.h>
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int s, n, j, i;
	scanf("%d", &n);
	for(s= 1; s<n; s++){
		for(i = 1; i<n-s; i++){
			j = i + s;
			printf("%d %d %d %d\n", s, n, i, j);
		}
	}

	return 0;
}
