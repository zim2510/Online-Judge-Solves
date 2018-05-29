#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;
int prime[MAX/64];
int nprime[664589];
int nprimes = 0;
bool check(int N,int pos){return (bool)(N & (1<<pos));}
int sset(int N,int pos){	return N=N | (1<<pos);}
void siv()
{
	for(int i = 3; i*i<=MAX; i+=2){
		if(!check(prime[i>>6], (i&((1<<7)-1))>>1)) for(int x = i*i; x<MAX; x+=2*i) prime[x>>6] = sset(prime[x>>6], (x&((1<<7)-1))>>1);
	}
	nprime[nprimes++] = 2;
	for(int i = 3; i<MAX; i+=2){
		if(!check(prime[i>>6], (i&((1<<7)-1))>>1)) nprime[nprimes++] = i;
	}
}

int main()
{
	siv();
	return 0;
}
