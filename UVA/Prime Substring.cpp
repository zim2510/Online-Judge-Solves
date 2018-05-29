#include <bits/stdc++.h>
#define MAX 100001
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
using namespace std;

int prime[100001];

void siv()
{
	prime[0] = prime[1] = 1;
	for(int i = 4; i<MAX; i+=2){
		prime[i] = 1;
	}
	for(int i = 3; i*i<MAX; i+=2){
		if(!prime[i]) for(int x = i*i; x<MAX; x+=2*i) prime[x] = 1;
	}
}

int main()
{

	READ();
	WRITE();

	siv();
	char in[256];
	while(scanf(" %s", in)){
		if(!strcmp(in, "0")) return 0;
		int len = strlen(in), mx = 1;
		for(int i = 0; i<len; i++){
			int num = 0;
			for(int sz = 0; sz<=4 && i+sz<len; sz++){
				num = num*10 + (in[i+sz] - '0');
				if(!prime[num] && num>mx) mx = num;
			}
		}
		printf("%d\n", mx);
	}
}