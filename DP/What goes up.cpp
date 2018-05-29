#include <bits/stdc++.h>

using namespace std;

int nums[1000000], seq[1000000], prv[1000000];
int path[1000000];

void pfind(int last, int index)
{
    if(index==0) return;
    path[index-1] = nums[last];
    pfind(prv[last], index-1);
}

int main()
{
    //memset(prv, -1, sizeof(prv));
    int n = 1;
    while(scanf("%d", &nums[n])==1) n++;

    int mx = 1;
    int last = n-1;

    for(int i = 1; i<=n; i++){
        seq[i] = 1;
        for(int j = 1; j<i; j++){
            if(nums[i]>nums[j]){
                if(seq[j]+1>=seq[i]){
                    seq[i] = seq[j] + 1;
                    prv[i] = j;
                    if(seq[i]>=mx){
                        mx = seq[i];
                        last = i;
                    }
                }
            }
        }
    }
    pfind(last, mx);
    printf("%d\n", mx);
    printf("-\n");
    for(int i = 0; i<mx; i++){
        printf("%d\n", path[i]);
    }
}
