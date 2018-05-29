#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n, product = 1;
    scanf("%lld", &n);

    for(long long i = 0, M = 1000000007; i<n; i++){
        long long int x;
        scanf("%lld", &x);
        product = (product * x)%M;
    }

    printf("%lld\n", product);
}
