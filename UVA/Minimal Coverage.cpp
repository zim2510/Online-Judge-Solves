#include <bits/stdc++.h>

using namespace std;

struct seg
{
    int sp, ep;
};

bool cmp(seg a, seg b)
{
    if(a.sp != b.sp) return a.sp<b.sp;
    else return a.ep>b.ep;
}


int main()
{
    //freopen("out.txt", "w", stdout);
    int tc;
    scanf("%d", &tc);

    for(int i = 1; i<=tc; i++){
        if(i!=1) printf("\n");
        int fp;
        scanf("%d", &fp);

        int sp, ep, x = 0;
        seg points[100000], out[100000];

        while(scanf("%d %d", &sp, &ep) && (sp || ep)){
            points[x].sp = sp;
            points[x].ep = ep;
            x++;
        }

        sort(points, points+x, cmp);
        int csp = 0, tep = 0, p = 0;

        for(int i = 0; i<x; i++){

            if(points[i].sp>csp){
                p++;
                csp = tep;
            }

            if(points[i].sp<=csp && points[i].ep>=fp){
                out[p].sp = points[i].sp;
                out[p].ep = points[i].ep;
                p++;
                tep = points[i].ep;
                break;
            }

            if(points[i].sp<=csp && points[i].ep>tep){
                tep = points[i].ep;
                out[p].sp = points[i].sp;
                out[p].ep = points[i].ep;
            }
        }
        if(tep>=fp){
            printf("%d\n", p);
            for(int i = 0; i<p; i++) printf("%d %d\n", out[i].sp, out[i].ep);
        }
        else printf("0\n");
    }
    return 0;
}
