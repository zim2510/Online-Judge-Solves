#include <bits/stdc++.h>

using namespace std;

int order[10], n, mn;

struct bpr
{
    int x, y;
};

bpr sp, loc[20];

int dcalc(bpr one, bpr two)
{
    int d = abs(one.x - two.x) + abs(one.y-two.y);
    return d;
}

int calc()
{
    //if(n == 9 && order[0] == 6 && order[1] == 3 && order[2] == 7 && order[3] == 4 && order[4] == 0 && order[5] == 1 && order[6] == 2 && order[7] == 5 && order[8] == 8)
    int dis = dcalc(loc[order[0]], sp);

    for(int i = 1; i<n; i++){
        dis += dcalc(loc[order[i]], loc[order[i-1]]);
        if(dis>mn) return mn+100;
    }

    dis += dcalc(loc[order[n-1]], sp);
    return dis;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tc;
    scanf("%d", &tc);

    for(int i = 0; i<tc; i++){
        int x, y;
        scanf("%d %d", &x, &y);

        scanf("%d %d", &sp.x, &sp.y);

        scanf("%d", &n);


        for(int i = 0; i<n; i++){
            order[i] = i;
            scanf("%d %d", &loc[i].x, &loc[i].y);
        }


        mn = calc();
        while(next_permutation(order, order+n)){
            int x = calc();
            if(x<mn) mn = x;
        }
        printf("The shortest path has length %d\n", mn);
    }
    return 0;
}



