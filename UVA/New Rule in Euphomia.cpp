#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;
int prime[MAX];
int nprime[78500];
int x = 0;

void siv(){
	prime[0] = prime[1] = 1;
	for(int i = 4; i<MAX; i+=2) prime[i] = 1;
	for(int i = 3; i*i<MAX; i+=2){
		if(!prime[i]) for(int x = i*i; x<MAX; x+=2*i) prime[x] = 1;
	}
	x = 0;
	nprime[x++] = 2;
	for(int i = 3; i<MAX; i+=2){
		if(!prime[i]) nprime[x++] = i;
	}
}

int main(int argc, char const *argv[]){
	siv();
	int n, tc = 0;
	while(scanf("%d", &n) && n){
		int sindex = lower_bound(nprime, nprime+x, n) - nprime - 1;
		int ways = 0;
		for(int i = sindex; i>0; i--){
			if(nprime[i]>n/2) ways += upper_bound(nprime, nprime+x, n-nprime[i]) - nprime;
			else ways += i;
		}
		printf("Case %d: %d\n", ++tc, ways);
	}
	return 0;
}

