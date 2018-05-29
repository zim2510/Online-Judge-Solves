#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    scanf("%d", &k);
    int grth[12];
    for(int i = 0; i<12; i++) scanf("%d", &grth[i]);
    sort(grth, grth+12, greater<int>());
    int g = 0, i;
    for(i = 0; i<12 && g<k; i++){
        g += grth[i];
    }
    if(g>=k) printf("%d\n", i);
    else printf("-1\n");
    return 0;

}
