#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("out.txt", "w", stdout);
    int np, nt, ns;

    while(scanf("%d %d %d", &nt, &np, &ns) && (nt||np||ns)){
        int ideal = 0;

        int teamsolve[151], onesolve = 0;
        memset(teamsolve, 0, sizeof(teamsolve));
        int probsolve[16], tprobsolve = 0;
        memset(probsolve, 0, sizeof(probsolve));
        int timsolve = 0, probslve = 0;
        int ish = -1, ism = -1, iss = -1, ieh = -1, iem = -1, ies = -1;

        for(int i = 0; i<ns; i++){
            int th, tm, ts, tid;
            char pid, verdict[100];
            scanf("%d %c %d:%d:%d", &tid, &pid, &th, &tm, &ts);
            scanf(" %[^\n]", verdict);
            if(ideal == -1) continue;

            if(strcmp("Yes", verdict)==0){
                teamsolve[tid]++;
                if(teamsolve[tid]==1) onesolve++;
                if(teamsolve[tid]==np) timsolve = 1;
                //printf("%d %d\n", onesolve, timsolve);
                probsolve[pid-'A']++;
                if(probsolve[pid-'A']==1) tprobsolve++;
                if(probsolve[pid-'A']==nt) probslve = 1;
                //printf("%d %d %d\n", probsolve[pid-'A'], tprobsolve, probslve);

            }

            if(onesolve == nt && tprobsolve == np && timsolve == 0 && probslve == 0){
                if(ideal==0){
                    ish = th;
                    ism = tm;
                    iss = ts;
                    ideal = 1;
                }
            }

            else if(ideal==1){
                ieh = th;
                iem = tm;
                ies = ts;
                ideal = -1;
            }

        }
            if(ideal==0) printf("--:--:-- --:--:--\n");
            else if(ideal == 1) printf("%02d:%02d:%02d --:--:--\n", ish, ism, iss);
            else printf("%02d:%02d:%02d %02d:%02d:%02d\n", ish, ism, iss, ieh, iem, ies);

    }

}

