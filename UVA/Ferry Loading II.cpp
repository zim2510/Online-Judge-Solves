#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d\n", &tc);

    for(int i = 0; i<tc; i++){
        int mx, t, ct;
        scanf("%d %d %d", &mx, &t, &ct);

        int loaded = 0, total = -1, ntrip = 0;
        for(int i = 0; i<ct; i++){
            int time;
            scanf("%d", &time);
            if(total<0) total = time + 2*t;

            if(loaded==mx){
                ntrip++;
                total = max(total, time) + 2*t;
                loaded = 1;
            }


            else if(loaded<mx){
                if(time<=total){
                    total = time + 2*t;
                    loaded++;
                }
                else if(time+2*t>total){
                    ntrip++;
                    total = time + 2*t;
                    loaded = 1;
                }
            }
        }
        printf("%d %d\n", total-t, ntrip);


    }
    return 0;
}
