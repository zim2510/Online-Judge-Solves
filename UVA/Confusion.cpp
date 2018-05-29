#include <bits/stdc++.h>

using namespace std;

int page[1000000];

int main()
{
    int tc;
    scanf("%d", &tc);

    for(int i = 1; i<=tc; i++){
        int n, p = 1;
        memset(page, 0, sizeof(page));
        scanf("%d", &n);
        for(int i = 0; i<n; i++){
            int x;
            scanf("%d", &x);
            page[x]++;
        }
        for(int i = 0; i<n; i++){
            if(page[i]){
                page[i]--;
            }
            else if(page[n-1-i]){
                page[n-1-i]--;
            }
            else{
                p = 0;
                break;
            }
        }

        printf("Case %d: %s\n", i, p?"yes":"no");

    }
}
