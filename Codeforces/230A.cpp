#include <bits/stdc++.h>

using namespace std;

struct drgn
{
    int pr, bns;
};

bool cmp(drgn a, drgn b)
{
    if(a.pr != b.pr) return a.pr<b.pr;
    else return a.bns>b.bns;
}

int main()
{
    int s, n;
    scanf("%d %d", &s, &n);
    drgn drag[n];
    for(int i = 0; i<n; i++){
        scanf("%d %d", &drag[i].pr, &drag[i].bns);
    }
    sort(drag, drag + n, cmp);
    int f = 0;
    for(int i = 0; i<n; i++){
        if(s<=drag[i].pr){
            f = 1;
            break;
        }
        else{
            s += drag[i].bns;
        }
    }
    if(!f) printf("YES\n");
    else printf("NO\n");



}
