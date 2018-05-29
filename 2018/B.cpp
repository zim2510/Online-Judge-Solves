#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main ()
{
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
    int tc;
    scanf("%d", &tc);

    for(int i = 1; i<=tc; i++){
    	int n, unsorted = 1;
    	scanf("%d", &n);
    	vector <int> nums(n), nums1, nums2;
        for(int i = 0; i<n; i++) scanf("%d", &nums[i]);
        for(int i = 0; i<n; i+=2) nums1.pb(nums[i]);
        for(int i = 1; i<n; i+=2) nums2.pb(nums[i]);
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for(int i = 0, p = 0; p<nums1.size(); i+=2, p++) nums[i] = nums1[p];
        for(int i = 1, p = 0; p<nums2.size(); i+=2, p++) nums[i] = nums2[p];
        int res = -1;
        for(int i = 0; i<n-1; i++){
            if(nums[i]>nums[i+1]){
                res = i;
                break;
            }
        }
        printf("Case #%d: ", i);
        if(res>=0) printf("%d\n", res);
        else printf("OK\n");
    }
    return 0;
}
