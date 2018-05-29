#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);

    for(int i = 1; i<=tc; i++){
        int n, k;
        scanf("%d %d", &n, &k);
        int nums[100];
        for(int i = 0; i<n; i++) scanf("%d", &nums[i]);
        sort(nums, nums+n);
        int clstr = 1;
        for(int i = 1; i<n; i++){
            if(nums[i]-nums[i-1] > k) clstr++;
        }
        printf("Case #%d: %d\n", i, clstr);
    }
    return 0;
}
