#include <bits/stdc++.h>

using namespace std;

int pr[100000], tmp[100000], n, s;

int bs(int k)
{
    sort(tmp, tmp + n);
    int cost = 0;
    for(int i = 0; i<k; i++){
        cost += tmp[i];
        if(cost>s) return -1;
    }
    return cost;
}

int main()
{
    scanf("%d %d", &n, &s);
    for(int i = 0; i<n; i++) scanf("%d", &pr[i]);
    int lo = 0, hi = n, mid, ans, mcost;
    while(lo<=hi){
        mid = (lo+hi)/2;
        for(int i = 0; i<n; i++){
            tmp[i] = pr[i] + mid*(i+1);
        }
        int x = bs(mid);

        if(x!=-1){
            ans = mid;
            mcost = x;
            lo = mid + 1;
        }

        else hi = mid - 1;
    }

    printf("%d %d\n", ans, mcost);

}
