#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);

    for(int i = 0; i<tc; i++){
        int n, m;
        scanf("%d %d", &n, &m);
        int result = 0;

        for(int x = m; x<=n; x *= m){
            result += n/x;
        }

        printf("%d\n", result);
    }
    return 0;
}
