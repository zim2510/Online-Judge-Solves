#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main()
{
    for(LL i = 1; ;i++){
        for(LL j = 1; j<=i; j++){
            cout<<i<<" "<<j<<" "<<i*i-j*j<<endl;
            if(i*i-j*j>1000000000) break;
        }
    }
}
