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

int prime[MAX], nprime[MAX];

void siv()
{
    prime[0] = prime[1] = 1;
    for(int i = 4; i<MAX; i+=2) prime[i] = 1;
    for(int i = 3; i*i<MAX; i+=2){
        if(!prime[i]) for(int x = i*i; x<MAX; x+=2*i) prime[x] = 1;
    }
    int n = 0;
    nprime[n++] = 2;
    for(int i = 3; i<MAX; i+=2){
        if(!prime[i]) nprime[n++] = i;
    }
    //printf("%d\n", nprime[n-1]);
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	siv();
	char input[20];
	while(scanf(" %s", input)==1){
		int mark = 0;
		int sum = 0, sum2 = 0;
		for(int i = 0;i<strlen(input); i++){
			sum = (sum*10) + input[i] - '0';
		}
		if(!prime[sum]){ 
			mark++;
			for(int i = strlen(input)-1;i>=0; i--){
				sum2 = (sum2*10) + input[i] - '0';
			}
			if(!prime[sum2] && sum!=sum2) mark++;
		}

		//printf("%d %d ", sum, sum2);

		//printf("\n%d %d %d\n", prime[sum], prime[sum2], mark);
		if(mark==2) printf("%d is erimp.\n", sum);
		else if(mark) printf("%d is prime.\n", sum);
		else printf("%d is not prime.\n", sum);
	}

	return 0;
}