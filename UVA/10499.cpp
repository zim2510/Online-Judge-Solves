#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n;
    while(scanf("%lld", &n) == 1 && n>0){
        printf("%lld%\n",n==1?0:n*25);
    }
    return 0;
}
