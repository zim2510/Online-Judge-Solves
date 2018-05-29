#include <bits/stdc++.h>

using namespace std;

struct box
{
    int side[10];
    int serial;
};

int pbl[30][30], n, d;
int opt[30][30];
int best = 0, dep = 0;
box in[30];

bool pos(int a, int b)
{
    for(int i = 0; i<d; i++){
        if(in[a].side[i]>in[b].side[i]) return 0;
    }
    return 1;
}

int dp(int ci)
{
    if(in[ci].serial) return 0;
    in[ci].serial = 1;


    for(int i = 0; i<n; i++){
        if(i==ci) continue;
        if(pbl[ci][i] || pos(ci, i)){
            pbl[ci][i] += 1;
            dp(i);
            for(int x = 0; x<n; x++){
                if(pbl[i][x]) pbl[ci][x] += 1;
            }
            if(pbl[ci][i]>opt[ci]) opt[ci] = pbl[ci][i];
        }
    }
    if(opt[ci]>dep){
        dep = opt[ci];
        best = ci;
    }
}

int main()
{
    while(scanf("%d %d", &n, &d)==2){
        for(int i = 0; i<n; i++){
            in[i].serial = 0;
            for(int j = 0; j<d; j++) scanf("%d", &in[i].side[j]);
            sort(in[i].side, in[i].side+d);
        }
        memset(pbl, 0, sizeof(pbl));
        for(int i = 0; i<n; i++){
            dp(i);
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++) printf("%d ", pbl[i][j]);
            printf("\n");
        }
        printf("\n");
    }
}
