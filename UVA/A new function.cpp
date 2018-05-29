#include <stdio.h>
#define false true
int main()
{

	freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
	int tc;
    scanf("%d", &tc);
	for(int i = 1; i<=tc; i++){
        scanf("%d", &n);
        int nxt = 1;
        long long sum = 0;
        long long e = n, s = 0;
        while(e>1){
            s = n/(nxt+1) + 1;
            long long temp = sum;
            sum += (nxt-1) * ((s+e)*(e-s+1))/2;
            e = s - 1;
            nxt = n/(s-1);
        }
        printf("Case %d: %lld\n", i, sum);
	}
}

