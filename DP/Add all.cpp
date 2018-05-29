#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int nums[5000];
    while(scanf("%d", &n) && n){
        for(int i = 0; i<n; i++) scanf("%d", &nums[i]);
        sort(nums, nums+n);
        int cost = 0;
        for(int i = 1; i<n; i++){
            nums[i] = nums[i] + nums[i-1];
            cost += nums[i];
            sort(nums+i, nums+n);
        }
        printf("%d\n", cost);
    }
}
