#include <bits/stdc++.h>

using namespace std;

long long two[35], mod[35];

long long calc()
{
    two[0] = 1;
    for(int i = 1; i<35; i++){
        two[i] = two[i-1]*2;
    }
    return 0;
}

long long modex(long long int x, long long int y, long long int m)
{

    mod[0] = x%m;

    for(int i = 1; two[i]<=y; i++){
        mod[i] = (mod[i-1]*mod[i-1])%m;
    }

    long long int result = 1;
    for(int i = 31; i>=0; i--){
        if(two[i]<=y){
            result = (result * mod[i])%m;
            y -= two[i];
        }
    }
    printf("%lld\n", result);
    return 0;
}

int main()
{
    calc();
    while(1){
        int tc;
        scanf("%d", &tc);
        if(tc==0) break;

        for(int i = 0; i<tc; i++){
            long long int x, y, m;
            scanf("%lld %lld %lld", &x, &y, &m);
            modex(x, y, m);
        }
    }
    return 0;
}
