#include <bits/stdc++.h>
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)

using namespace std;

int nums[6];
int opt[6][200000];

int dp(int ci, int total)
{
	if(total==0) return 1;
	if(ci>5) return 0;
	if(opt[ci][total]!=-1) return opt[ci][total];

	for(int i = 0; i<=nums[ci]; i++){
		opt[ci][total] = dp(ci+1, total-(ci+1)*i);
		if(opt[ci][total]==1) break;
	}
	return opt[ci][total];
}

int main()
{
	//READ();
	//WRITE();

	int t = 0;
	while(scanf("%d %d %d %d %d %d", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4], &nums[5])==6){
		int total = nums[0]+nums[1]*2+nums[2]*3+nums[3]*4+nums[4]*5+nums[5]*6;
		if(total==0) break;
		memset(opt, -1, sizeof(opt));
		printf("Collection #%d:\n", ++t);
		if(total%2){
			printf("Can't be divided.\n\n");
			continue;
		}
		int pos = dp(0, total/2);
		if(pos) printf("Can be divided.\n");
		else printf("Can't be divided.\n");
		printf("\n");
	}

}