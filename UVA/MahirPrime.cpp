#include <bits/stdc++.h>

using namespace std;

int nprime[1000000];

void gen()
{
    nprime[0] = 2;
    nprime[1] = 3;
    nprime[2] = 5;
    nprime[3] = 7;
    int x = 4;

    for(int i = 8; nprime[10000]==0; i++){
        int flag = 0;
        for(int j = 0; nprime[j]!=0; j++){
            if(i%nprime[j]==0){
                flag = 1;
                break;
            }
        }
        if(!flag) nprime[x++] = i;
    }
    printf("%d\n", nprime[10000]);
}


int main()
{
    gen();
}
