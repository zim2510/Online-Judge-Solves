#include <bits/stdc++.h>

using namespace std;


int modex(int x, int y, int m)
{
    long long result = 1;
    for(int i = 0; i<y; i++){
        result = (result * x)%m;
    }
    printf("%lld\n", result);
    return 0;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for(int i = 0; i<tc; i++){
        long long int x, y, m;
        scanf("%lld %lld %lld", &x, &y, &m);
        modex(x, y%m, m);
    }
    return 0;
}
