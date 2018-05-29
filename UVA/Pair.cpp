#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, k;
    long long nums[100000];

    scanf("%I64d %I64d", &n, &k);

    for(int i = 0; i<n; i++) scanf("%I64d", &nums[i]);
    sort(nums, nums+n);

    int l = (k-1)/n;
    int m = (k-1)%n;

    printf("%I64d %I64d\n", nums[l], nums[m]);
    return 0;
}


/*
    long long int x = 0;
    long long int i;

    for(i = 0; i<n; i++){
        if((x+n)<k) x += n;
        else break;
    }


    printf("%I64d %I64d\n", nums[i], nums[k-1-x]);*/
