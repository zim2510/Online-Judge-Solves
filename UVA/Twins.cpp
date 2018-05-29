#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int in[n];
    for(int i = 0; i<n; i++) scanf("%d", &in[i]);

    int mx = 0;
    int o = 0;
    for(int i = 0; i<n; i++){
        if(in[i]) o++;
        else {
            int z = 0;
            for(int x = i; x<n; x++){
                if(in[x]==0){
                    z++;
                    if(z>mx) mx = z;
                }
                else z--;
            }
        }
    }
    if(n == o) printf("%d\n", o - 1);
    else printf("%d\n", o+mx);

    return 0;
}
