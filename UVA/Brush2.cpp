#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);

    for(int i = 1; i<=tc; i++){
        int t, w;
        scanf("%d %d", &t, &w);
        int cy[t], temp;
        for(int i = 0; i<t; i++){
            scanf("%d %d", &temp, &cy[i]);
        }
        sort(cy, cy+t);
        int counter = 0;
        for(int i = 0, init = cy[0]; i<t; i++){
            if(cy[i]>init+w){
                counter++;
                init = cy[i];
            }
        }
        printf("Case %d: %d\n", i, counter+1);
    }
}
