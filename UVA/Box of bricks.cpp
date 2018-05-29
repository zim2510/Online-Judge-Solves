#include <bits/stdc++.h>

using namespace std;

void sum(int n)
{
    int s = 0;
    while(n!=0){
        s += n%10;
        n = n/10;
    }
    if(s<=9) printf("%d\n", s);
    else sum(s);
}

int main()
{
    int n;
    while(scanf("%d", &n)==1){
        sum(n);
    }
}
