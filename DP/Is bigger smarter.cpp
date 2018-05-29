#include <bits/stdc++.h>

using namespace std;

struct eli
{
    int w;
    int iq;
};

eli in[1000];
int opt[1000], n = 0;
int path[1000];

int dp(int ci)
{
    if(opt[ci]!=-1) return opt[ci];
    opt[ci] = 0;
    for(int i = 0; i<n; i++){
        if(in[i].w>in[ci].w && in[i].iq<in[ci].iq){
            int t = 1 + dp(i);
            if(t>opt[ci]){
                opt[ci] = t;
                path[ci] = i;
            }
        }
    }
    return opt[ci];
}

int main()
{
    int mx = 0, last;
    memset(opt, -1, sizeof(opt));
    while(scanf("%d %d", &in[n].w, &in[n].iq)==2) n++;
    for(int i = 0; i<n; i++){
        int t = dp(i);
        if(t>mx){
            mx = t;
            last = i;
        }
    }
    printf("%d\n", mx+1);
    printf("%d\n", last+1);
    for(int i = 0; i<mx; i++){;
        printf("%d\n", path[last]+1);
        last = path[last];
    }
}

