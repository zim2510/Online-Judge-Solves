#include <bits/stdc++.h>
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
using namespace std;

int main()
{
    READ();
    WRITE();

    long long int n, m, f = 0;
    while(scanf("%lld %lld", &n, &m)==2){
    	long long x = 1;
    	for(long long int i = n; i>(n-m); i--){
    		x *= i;
    		while(x%10==0) x/=10;
    		x = x%100000000;
    	}
    	printf("%lld\n", x%10);
 	}

 	return 0;
 }