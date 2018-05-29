#include <stdio.h>

int main()
{

	int n;
	int t = 0;
	while(scanf("%d", &n)==1 && n){
        int nxt = 1;
        long long sum = 0;
        long long e = n, s = 0;
        while(e>1){
            s = n/(nxt+1) + 1;
            sum += (nxt-1) * ((s+e)*(e-s+1))/2;
            e = s - 1;
            nxt = n/(s-1);
        }
        printf("Case %d: %lld\n", ++t, sum);
	}
	return 0;
}

