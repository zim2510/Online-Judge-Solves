#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);

    for(int i = 1; i<=tc; i++){
        int n;
        int mtm[50], otm[50];
        scanf("%d", &n);
        for(int i = 0; i<n; i++) scanf("%d", &mtm[i]);
        for(int i = 0; i<n; i++) scanf("%d", &otm[i]);

        sort(mtm, mtm+n);
        sort(otm, otm+n);

        int point = 0;

        for(int i = 0, j = 0; i<n && j<n; ){
            if(mtm[i]>otm[j]){
                point += 2;
                mtm[i] = 0;
                mtm[j] = 0;
                i++; j++;
            }
            else i++;
        }

        sort(mtm, mtm+n);
        sort(otm, otm+n);

        for(int i = 0, j = 0; i<n && j<n; ){
            if(mtm[i]>=otm[j] && otm[j]<=0){
                point += 1;
                mtm[i] = 0;
                mtm[j] = 0;
                i++; j++;
            }
            else i++;
        }



        printf("Case %d: %d\n", i, point);
    }
}
