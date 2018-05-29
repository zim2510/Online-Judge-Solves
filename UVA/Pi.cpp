#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n)==1 && n){
        int nums[n];
        double npair = (n*(n-1))/2, cpair = npair;
        for(int i = 0; i<n; i++) scanf("%d", &nums[i]);
        for(int i = 0; i<n; i++){
            for(int j = i + 1; j<n; j++){
                //printf("%lf\n",cpair);
                if(__gcd(nums[i], nums[j])!=1) cpair--;
            }
        }

        if(cpair==0) {printf("No estimate for this data set.\n"); continue;}
        cpair = cpair/6;
        npair = npair/cpair;
        npair = sqrt(npair);
        printf("%lf\n", npair);

    }
}
