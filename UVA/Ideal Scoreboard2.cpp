#include <bits/stdc++.h>

using namespace std;

struct submission
{
    int tid, pid, th, tm, ts;
    char verdict[100];
};

bool cmp(submission a, submission b)
{
    if(a.th!=b.th) return a.th<b.th;
    if(a.tm!=b.tm) return a.tm<b.tm;
    if(a.ts!=b.ts) return a.ts<b.ts;
}


int main()
{
    int np, nt, ns;

    while(scanf("%d %d %d", &nt, &np, &ns) && (nt||np||ns)){
        submission sub[5000];
        int cnt = 0;
        for(int i = 0; i<ns; i++, cnt++){
            scanf("%d %c %d:%d:%d", &sub[cnt].tid, &sub[cnt].pid, &sub[cnt].th, &sub[cnt].tm, &sub[cnt].ts);
            scanf(" %[^\n]", sub[cnt].verdict);
            if(strcmp("Yes", sub[cnt].verdict)!=0) cnt--;
        }

        sort(sub, sub+cnt, cmp);


        int ideal = 0;

        int teamsolve[151][16];
        int sol[151], probsolve[16];
        memset(sol, 0, sizeof(sol));
        memset(teamsolve, 0, sizeof(teamsolve));
        memset(probsolve, 0, sizeof(probsolve));

        int ish, ism, iss, ieh, iem, ies;
        int timslv = 0, prbslv = 0;
        int onesolve = 0, tprobsolve = 0;

        for(int i = 0; i<cnt; i++){

            int tid = sub[i].tid;
            int pid = sub[i].pid;
            int th = sub[i].th;
            int tm = sub[i].tm;
            int ts = sub[i].ts;


            if(teamsolve[tid][pid-'A']==0){
                teamsolve[tid][pid-'A'] = 1;

                probsolve[pid-'A']++;
                if(probsolve[pid-'A']==1) tprobsolve++;
                if(probsolve[pid-'A']==nt) prbslv = 1;

                sol[tid]++;
                if(sol[tid]==1) onesolve++;
                if(sol[tid]==np) timslv = 1;
            }

            if(onesolve == nt && tprobsolve == np && timslv == 0 && prbslv == 0){
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
                break;
            }
        }

        if(ideal==0) printf("--:--:-- --:--:--\n");
        else if(ideal == 1) printf("%02d:%02d:%02d --:--:--\n", ish, ism, iss);
        else printf("%02d:%02d:%02d %02d:%02d:%02d\n", ish, ism, iss, ieh, iem, ies);

    }
    return 0;
}

