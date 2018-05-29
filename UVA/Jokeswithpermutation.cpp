#include <bits/stdc++.h>

using namespace std;

char in[1000];
int si, dou, mx, len, found, chk[51];
int cnts, cntd, val = 0, print[51];


void btrack(int point, int level)
{
    if(val==1) return;
    if(found==mx){
        val = 1;
        for(int i = 1; i<=mx; i++){
            print[chk[i]-1] = i;
        }
        printf("%d", print[0]);
        for(int i = 1; i<mx; i++) printf(" %d", print[i]);
        printf("\n");
        return;
    }
    if(point>=len) return;

    if(cnts<si){
        int x = in[point]-'0';
        if(x<=mx && chk[x]==0){
            chk[x] = level+1;
            cnts++;
            found++;
            //printf("In level %d: %d\n", level, x);
            btrack(point+1, level+1);
            chk[x] = 0;
            cnts--;
            found--;
        }
    }

    if(cntd<dou){
        int x = (in[point]-'0')*10 + (in[point+1]-'0');
        if(x<=mx && chk[x]==0){
            chk[x] = level+1;
            found++;
            cntd++;
            //printf("In level %d: %d\n", level, x);
            btrack(point+2, level+1);
            chk[x] = 0;
            found--;
            cntd--;
        }
    }
    return;
}

int main()
{
    while(scanf(" %s", in)==1){
        len = strlen(in);
        mx = len>9?(len-9+18)/2:len;
        si = mx>9?9:mx;
        dou = mx>9?mx-9:0;
        cnts = 0; cntd = 0; val = 0; found = 0;
        for(int i = 0; i<=mx; i++) chk[i] = 0;
        btrack(0, 0);
    }
}
