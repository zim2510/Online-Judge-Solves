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

int ephi[10000000];
LL sumphi[10000000];
int nprime[MAX], nprimes = 0;

void phisiv()
{
	ephi[0] = 1; for(int i = 1; i<MAX; i++) ephi[i] = i;
	for(int i = 2; i<MAX; i++){
		if(ephi[i]==i){
			nprime[nprimes++] = i;
			for(int x = i; x<MAX; x += i){
				ephi[x] -= (ephi[x]/i);
			}
		}
	}
	sumphi[0] = 1;
	for(int i = 1; i<MAX; i++) sumphi[i] = sumphi[i-1] + ephi[i];
}

vector <int> factorized;
void factorize(int n)
{
	for(int i = 0; i<nprimes && nprime[i]*nprime[i]<=n; i++){
		while(n%nprime[i]==0){
			factorized.pb(nprime[i]);
			n /= nprime[i];
		}
	}
	if(n!=1) factorized.pb(n);
}

int katar[MAX];
int katakuti(int lmt, int n)
{
	
	int cnt = 0;
	for(int i = 1; i<lmt; i++){
		if(__gcd(i, lmt)==1) cnt++;
		if(cnt==n) return i;
	}
}

int solve(LL n)
{
	int x = 0, rest;
	/*x = upper_bound(sumphi, sumphi+MAX, n) - sumphi - 1;
	//printf("%d\n", x);
	//rest = n - sumphi[x-1];

	for(int i = 0; i<MAX; i++){
		if(sumphi[i]>=n){
			x = i;
			//printf("%d\n", x);
			rest = n - sumphi[i-1];
			break;
		}
	}*/


	/**************************BinarySearch******************************/
	long long left = 0, right = sumphi+MAX-1, mid, target;
	while(left < right)
	{
		mid = (left+right)>>1LL;
		if(sumphi[ mid ] < n) left = mid + 1;
		else right = mid;
	}
	target = sumphi[ letf ]
	/**************************BinarySearchEnd***************************/

	int y = katakuti(x, rest);
	printf("%d/%d\n", y,x);
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	//cout<<sizeof(long)<<" "<<sizeof(long long)<<" "<<sizeof(int)<<endl;
	//long xx = 1<<31-1;
	//int xxx = 1<<31-1;
	//printf("%ld %d\n", xx, xxx);
	phisiv();
	LL n;
	while(scanf("%lld", &n) && n){
        if(n==1) printf("0/1\n");
        else if(n==2) printf("1/1\n");
        else solve(n);
	}
	return 0;
}
