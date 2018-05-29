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

int nums[MAX];

int main(int argc, char const *argv[])
{
	Read();
	Write();
	int n;
	while(scanf("%d", &n)==1){
		int neg = 0;
		for(int i = 0; i<n; i++){
			scanf("%d", &nums[i]);
			if(nums[i]<0) neg++;
		}
		int moves = 0;
		while(neg){
			//printf("%d\n", neg);
			for(int i = 0; i<n; i++){
				if(nums[i]<0){
					nums[i] *= -1;
					moves++;
					neg--;
					if(i==0){
						if(nums[n-1]>=0 && nums[n-1]<nums[i]) neg++;
						nums[n-1] -= nums[i];
						if(nums[i+1]>=0 && nums[i+1]<nums[i]) neg++;
						nums[i+1] -= nums[i];
					}
					else if(i==n-1){
						if(nums[0]>=0 && nums[0]<nums[i]) neg++;
						nums[0] -= nums[i];
						if(nums[i-1]>=0 && nums[i-1]<nums[i]) neg++;
						nums[i-1] -= nums[i];
					}
					else{
						if(nums[i-1]>=0 && nums[i-1]<nums[i]) neg++;
						nums[i-1] -= nums[i];
						if(nums[i+1]>=0 && nums[i+1]<nums[i]) neg++;
						nums[i+1] -= nums[i];
					}
				}
			}
		}
		printf("%d\n", moves);


	}

	return 0;
}
