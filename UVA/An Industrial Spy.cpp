#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define REP(i, a, b)      for(int i = a; a<=b; i++)
#define FOR(i, a, b)      for(int i = a; a<b; i++)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)			  ((x)*(x))

#define pb   push_back
#define LL   long long
#define ULL  unsigned long long
#define MAX  10000000

using namespace std;

//Total Prime Sieve
int prime[MAX], nprime[664580];
int nprimes = 0;
int mark[7];
int marked[10000000];

void siv()
{
	prime[0] = prime[1] = 1;
	for(int i = 4; i<MAX; i+=2) prime[i] = 1;
	for(int i = 3; i*i<MAX; i+=2){
		if(!prime[i]) for(int x = i*i; x<MAX; x+=2*i) prime[x] = 1;
	}
	nprime[nprimes++] = 2;
	for(int i = 3; i<MAX; i+=2){
		if(!prime[i]) nprime[nprimes++] = i;
	}
}

string in;
int cnt;
int check;

void btrack(int pos, int sum)
{
	//printf("%d %d\n", pos, sum);
	if(pos==in.size()){
		if(!prime[sum] && marked[sum]<check){
			marked[sum] = check;
			cnt++;
		}
		return;
	}
	if(!prime[sum] && marked[sum]<check){
		marked[sum] = check;
		cnt++;
	}
	for(int i = 0; i<in.size(); i++){
		if(!mark[i]){
			mark[i] = 1;
			btrack(pos+1, sum*10+in[i]-'0');
			mark[i] = 0;
		}
	}
}

int main()
{
	//Read();
	//Write();
	siv();
	int tc;
	scanf("%d", &tc);
	for(int i = 1; i<=tc; i++){
		cin>>in;
		cnt = 0;
		check++;
		btrack(0, 0);
		printf("%d\n", cnt);
	}

}