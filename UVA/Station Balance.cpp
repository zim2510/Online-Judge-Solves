#include <bits/stdc++.h>

using namespace std;

int main()
{
    int c, m;
    int tc = 0;
    while(scanf("%d %d", &c, &m)==2){
        int chamber[5][2], mass[10];


        double total = 0, ibl = 0, amass;
        for(int i = 0; i<m; i++) scanf("%d", &mass[i]);
        for(int i = 0; i<m; i++) total += mass[i];
        amass = total/c;


        for(int i = 0; i<c; i++) chamber[i][0] = chamber[i][1] = 0;
        sort(mass, mass + m, greater<int>());

        int ls = 0;
        if(m>c && m<2*c) ls = 2*c - m;

        for(int i = 0; i<m && ls+i<c; i++){
            chamber[ls+i][0] = mass[ls+i];
            if(ls || m==c*2) chamber[ls+i][1] = mass[m-1-i];
        }

        for(int i = 0; i<ls; i++){
            chamber[i][0] = mass[i];
        }


        printf("Set #%d\n", ++tc);
        for(int i = 0; i<c; i++){
            printf("%2d:", i);
            if(chamber[i][0]) printf(" %d", chamber[i][0]);
            if(chamber[i][1]) printf(" %d", chamber[i][1]);
            printf("\n");
            double tmass = double(chamber[i][0]+chamber[i][1]);
            ibl += abs(tmass - amass);
        }
        printf("IMBALANCE = %0.5lf\n\n", ibl);
    }
}
