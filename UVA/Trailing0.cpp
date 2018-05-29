#include <bits/stdc++.h>

using namespace std;

bool prime[1000000000];

void siv(long long int n)
{
    for(long long int i = 4; i<n; i+=2){
        prime[i] = 1;
    }
    for(long long int i = 3; i*i<n; i++){
        if(prime[i]==0){
            for(long long int x = i*i; x<n; x+=i){
                prime[x] = 1;
            }
        }
    }
}

int main()
{
    siv(1000000000);
}
