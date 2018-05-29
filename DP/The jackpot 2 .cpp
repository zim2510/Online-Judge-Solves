#include <bits/stdc++.h>

using namespace std;

int opt[10001][10001], nums[10000], n, mx;

int main()
{
      while(scanf("%d", &n)==1 && n){
            mx = 0;
            for(int i = 1; i<=n; i++){
                scanf("%d", &nums[i]);
            }
            for(int i = 1; i<=n; i++){
                if(nums[i]<0) continue;
                for(int j = i; j<=n; j++){
                    opt[i][j] = nums[j] + opt[i][j-1];
                    if(opt[i][j]>mx) mx = opt[i][j];
                    else if(opt[i][j]<0) break;
                }
            }
            if(!mx) printf("Losing streak.\n");
            else printf("The maximum winning streak is %d.\n", mx);
      }
}
