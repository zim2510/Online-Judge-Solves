#include <bits/stdc++.h>

using namespace std;
long long nums[500], n, np, mx;
long long serial[1000];

void bin(long long lo, long long hi)
{
    long long mid;
    long long par = 1;
    while(hi>=lo){
        mid = (hi+lo)/2;
        if(hi==lo) break;
        long long curr = 0;
        par = 1;

        for(long long i = 0; i<n; i++){
            if(curr+nums[i]>mid){
                curr = nums[i];
                par++;
            }
            else{
                curr += nums[i];
            }
        }
        if(par<=np) hi = mid;
        else if(par>np) lo = mid + 1;
    }
    mx = mid;
}

long long calc()
{
    //printf("%lld\n", mx);
    long long x = 0, on = n-1;
    for(long long pr = np; pr>0 ; pr--){
        long long psize = 0;
        for(; on+1>=pr; on--){
            if(psize+nums[on]>mx) break;
            psize += nums[on];
            serial[x++] = nums[on];
        }
        serial[x++] = 0;
    }

    printf("%lld", serial[x-2]);
    for(long long i = x-3; i>=0; i--){
        if(serial[i]) printf(" %lld", serial[i]);
        else printf(" /");
    }
    printf("\n");
}



int main()
{
    //freopen("out.txt", "w", stdout);
    long long tc;
    scanf("%lld", &tc);

    for(long long i = 0; i<tc; i++){
        scanf("%lld %lld", &n, &np);
        long long hi = 0, lo = 0;
        for(long long i=0; i<n; i++){
            scanf("%lld", &nums[i]);
            hi += nums[i];
            if(nums[i]>lo) lo = nums[i];
        }

        bin(lo, hi);
        calc();
    }
    return 0;
}
