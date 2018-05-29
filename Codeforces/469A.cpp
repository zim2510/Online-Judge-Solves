#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int lvl[n];
    memset(lvl, 0, sizeof(lvl));

    int cnt = 0;
    int p, z;

    scanf("%d", &p);
    for(int i = 0; i<p; i++){
        int x;
        scanf("%d", &x);
        if(!lvl[x-1]){
            lvl[x-1] = 1;
            cnt++;
        }
    }
    scanf("%d", &z);
    for(int i = 0; i<z; i++){
        int x;
        scanf("%d", &x);
        if(!lvl[x-1]){
            lvl[x-1] = 1;
            cnt++;
        }
    }
    if(n==cnt) printf("I become the guy.\n");
    else printf("Oh, my keyboard!\n");
    return 0;


}
