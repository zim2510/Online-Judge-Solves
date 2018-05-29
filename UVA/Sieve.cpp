#include <bits/stdc++.h>
#define MAX 10000000
using namespace std;
int prime[MAX/2], nprime[664589];
int nprimes = 0;

void siv()
{
	for(int i = 3; i*i<MAX; i+=2){
		if(!prime[i>>1]) for(int x = i*i; x<MAX; x+=2*i) prime[x>>1] = 1;
	}
	nprime[nprimes++] = 2;
	for(int i = 1; i<(MAX>>1); i++){
		if(!prime[i]) nprime[nprimes++] = (i<<1)+1;
	}
	cout<<nprimes<<endl;
}
int main()
{
    siv();
}
