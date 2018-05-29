#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n;
    scanf("%lld", &n);
    if(n%2){
        printf("%lld\n", n/2 - n);
    }
    else printf("%lld\n", n/2);
    return 0;
}
