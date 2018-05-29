#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n) && n){
        int city[n];
        for(int i = 1; i<n; i++){
            int cnt = 0, cc = 0, cutted = 1;
            memset(city, 0, sizeof(city));

            city[0] = 1;

            for(cutted = 1; cutted<=n && !city[12]; cutted++){
                while(cnt!=i){
                    cc = (cc+1)%n;
                    if(!city[cc]) cnt++;
                }
                city[cc] = 1;
                cnt = 0;
            }
            if(cutted==n){
                printf("%d\n", i);
                break;
            }

        }
    }
}
