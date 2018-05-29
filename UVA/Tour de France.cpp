#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("out.txt", "w", stdout);
    while(1)
    {
        int nf, nr;
        scanf("%d", &nf);
        if(nf == 0) return 0;
        else scanf("%d", &nr);

        int f[nf], r[nr];
        for(int i = 0; i<nf; i++) scanf("%d", &f[i]);
        for(int i = 0; i<nr; i++) scanf("%d", &r[i]);

        vector <double> vel;
        int cnt = 0;

        for(int i = 0; i<nf; i++){
            for(int j = 0; j<nr; j++){
                double x = (double) r[j] / f[i];
                vel.push_back(x);
                cnt++;
            }
        }
        sort(vel.begin(), vel.end());
        vector <double> sprd;
        for(int i = 1; i<cnt; i++){
            double x = vel[i] / vel[i-1];
            sprd.push_back(x);
        }
        sort(sprd.begin(), sprd.end());
        printf("%0.2lf\n", sprd[cnt - 2]);
    }


}
