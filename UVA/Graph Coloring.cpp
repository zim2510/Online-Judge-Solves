#include <bits/stdc++.h>

using namespace std;

int clr[101];
int sol[101];
int graph[101][101];
int n, e, mx = 0;

int check(int x);

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tc;
    scanf("%d", &tc);

    for(int i = 0; i<tc; i++){
        scanf("%d %d", &n, &e);


        memset(clr, 0, sizeof(clr));
        memset(graph, 0, sizeof(graph));


        for(int i = 0; i<e; i++){
            int nd1, nd2;
            scanf("%d %d", &nd1, &nd2);
            graph[nd1][nd2] = 1;
            graph[nd2][nd1] = 1;
        }
        mx = 0;
        check(1);
        printf("%d\n", mx);
        printf("%d", sol[0]);
        for(int i = 1; i<mx; i++) printf(" %d", sol[i]);
        printf("\n");
    }
}

int check(int x)
{
    //printf("Color %d: %s\n", x, clr[x]>0?"Black":(clr[x]<0?"White":"No color"));
    if(x>n){
        int cnt = 0;
        for(int i = 1; i<=n; i++){
            if(clr[i]>0) cnt++;
        }
        if(cnt>mx){
            mx = cnt;
            int index = 0;
            for(int i = 1; i<=n; i++){
                if(clr[i]>0) sol[index++] = i;
            }
        }
    }

    else if(clr[x]!=0) check(x+1);

    else if(!clr[x]){
        clr[x]++;
        //printf("New Color %d: %s\n", x, clr[x]>0?"Black":"White");
        for(int i = 1; i<=n; i++){
            if(graph[x][i]){
                clr[i]--;
            }
        }
        check(x+1);
        clr[x]--;
        //printf("Changed New Color %d: %s\n", x, clr[x]>0?"Black":"White");
        for(int i = 1; i<=n; i++){
            if(graph[x][i]) clr[i]++;
        }
        check(x+1);
    }
    //printf("Happy returning\n");
}
