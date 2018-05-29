#include <bits/stdc++.h>

using namespace std;

int aw[20001], opt[20001], n;
int mx, ep, sp;

void dp(int i, int s)
{
    if(i>=n) return;
    else opt[i] = opt[i-1] + aw[i];
    if(opt[i]<0) opt[i] = 0, s = i;
    if(opt[i]>mx || (opt[i]==mx && ep-sp<i-s)){
        ep = i;
        sp = s;
        mx = opt[i];
    }
    dp(i+1, s);
}

int main()
{
    //freopen("out.txt", "w", stdout);
    int tc;
    scanf("%d", &tc);
    for(int i = 1; i<=tc; i++){
        scanf("%d", &n);
        for(int i = 1; i<n; i++) scanf("%d", &aw[i]);
        memset(opt, 0, sizeof(opt));
        mx = 0;
        dp(1 , 0);
        if(mx==0) {printf("Route %d has no nice parts\n", i) ; continue;}
        /*int sp;
        for(int i = 1; ;i++){
            if(opt[i]==mx) {ep = i; break;}
        }
        for(int i = ep - 1; ;i--){
            if(opt[i]==0) {sp = i; break;}
        }*/
        printf("The nicest part of route %d is between stops %d and %d\n", i, sp+1, ep+1);
    }
}
