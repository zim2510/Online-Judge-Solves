#include <bits/stdc++.h>

using namespace std;

int main()
{
    int nd, nk;
    while(scanf("%d %d", &nd, &nk) && (nd || nk)){
        int hs[nd], hk[nk];
        for(int i = 0; i<nd; i++) scanf("%d", &hs[i]);
        sort(hs, hs+nd);
        for(int i = 0; i<nk; i++) scanf("%d", &hk[i]);
        sort(hk, hk+nk);
        int sum  = 0;
        int i = 0;
        for(int j = 0; i<nd && j<nk; j++){
            if(hk[j]>=hs[i]){
                sum += hk[j];
                i++;
            }
        }
        if(i==nd) printf("%d\n", sum);
        else printf("Loowater is doomed!\n");
    }
}
