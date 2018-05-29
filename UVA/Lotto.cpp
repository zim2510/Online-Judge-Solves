#include <bits/stdc++.h>

using namespace std;

void btrack(int x, int y);

int nums[15], n, out[6];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tc = 0;
    while(scanf("%d", &n) && n){
        if(tc++ != 0) printf("\n");
        for(int i = 0; i<n; i++){
            scanf("%d", &nums[i]);
        }
        sort(nums, nums + n);
        btrack(0, 0);
    }
}

void btrack(int x, int y){

    if(x==6){
        printf("%d %d %d %d %d %d\n", out[0], out[1], out[2], out[3], out[4], out[5]);
        return;
    }
    for(int i = y; i<n; i++){
        out[x] = nums[i];
        //printf("%d %d %d\n", i, x, n);
        btrack(x+1, i+1);
    }
}
