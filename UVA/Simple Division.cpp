#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("out.txt", "w", stdout);
    int nums[1000];
    int num;
    int n = 0;
    while(scanf("%d", &num)==1){
        if(!n && !num) break;
        if(n && !num){
            int diff[n-1];
            for(int i = 0; i<n-1; i++){
                diff[i] = abs(nums[i+1] - nums[i]);
            }
            int g = diff[0];
            for(int i = 1; i<n-1; i++){
                g = __gcd(diff[i], g);
            }
            printf("%d\n", g);
            n = 0;
        }
        else nums[n++] = num;
    }
}
