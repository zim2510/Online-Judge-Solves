#include <bits/stdc++.h>

using namespace std;

struct box
{
    int side[10];
};

int n, d;
int opt[30], path[31];
int best = 0, dep = 0;
box in[30];

bool pos(int a, int b)
{
    for(int i = 0; i<d; i++){
        if(in[a].side[i]>=in[b].side[i]) return 0;
    }
    return 1;
}


int dp(int ci)
{
    if(opt[ci]!=-1) return opt[ci];
    for(int i = 0; i<n; i++){
        if(i!=ci && pos(ci, i)){
            if(1+dp(i)>opt[ci]){
                opt[ci] = 1 + dp(i);
                path[ci+1] = i;
            }
        }
    }
    if(opt[ci]==-1) opt[ci] = 0;
    return opt[ci];

}

int main()
{
        //freopen("out.txt", "w", stdout);
        while(scanf("%d %d", &n, &d)==2){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<d; j++) scanf("%d", &in[i].side[j]);
                sort(in[i].side, in[i].side+d);
            }
            memset(opt, -1, sizeof(opt));
            int mx = 0;
            int last;
            for(int i = 0; i<n; i++){
                int n = dp(i);
                if(n>mx){
                    mx = n;
                    last = i;
                }
            }
            printf("%d\n", mx+1);
            printf("%d", last+1);
            for(int i = 0; i<mx; i++){
                printf(" %d", path[last+1]+1);
                last = path[last+1];

            } printf("\n");
        }
}
