#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n;
	while(scanf("%lld", &n) && n>0){
        if(n%2==0){
            while(n%2==0){
                printf("    2\n");
                n /= 2;
            }
        }
		for(int i = 3; i*i<n; i++){
			if(n%i==0){
				while(n%i==0){
					printf("    %d\n", i);
					n /= i;
				}
			}
		}
		if(n>1) printf("    %lld\n", n);
		printf("\n");
	}
}
