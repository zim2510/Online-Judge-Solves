#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);
    for(int i = 0; i<tc; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        int gcd = min(a, b);
        for(; gcd>0; gcd--){
            if(a%gcd == 0 && b%gcd == 0) break;
        }
        printf("%d\n", gcd);
    }
}
