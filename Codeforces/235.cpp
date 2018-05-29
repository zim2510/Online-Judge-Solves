#include <bits/stdc++.h>

using namespace std;
void perm(int x);
void calc(int x, long long int sum);

long long int nums[5], mark[5], permuted[5], pos;

int main()
{
    while(1){
        int zc = 0;
        for(int i = 0; i<5; i++){
            scanf("%lld", &nums[i]);
            if(!nums[i])zc++;
        }
        pos = 0;
        if (zc == 5) break;

        else perm(0);
        if(pos) printf("Possible\n");
        else printf("Impossible\n");
    }
}

void perm(int x){
    if(pos) return;
    if(x==5){
        calc(0, 0);
        return;
    }
    for(int i = 0; i<5; i++){
        if(!mark[i]){
            permuted[x] = nums[i];
            mark[i] = 1;
            perm(x+1);
            mark[i] = 0;
        }
    }
}

void calc(int x, long long int sum)
{
    if(x==5){
        if(sum==23) pos = 1;
        return;
    }

    calc(x+1, sum+permuted[x]);
    if(x>0) calc(x+1, sum-permuted[x]);
    if(x>0) calc(x+1, sum*permuted[x]);
}
