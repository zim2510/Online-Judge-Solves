#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define REP(i, a, b)      for(int i = a; a<=b; i++)
#define FOR(i, a, b)      for(int i = a; a<b; i++)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)            ((x)*(x))

#define pb   push_back
#define LL   long long
#define ULL  unsigned long long
#define MAX  10000000

using namespace std;

struct stations
{
    double dio, price;
};

double gcap, mpg, cost;
stations station[100];
double distanc;
double mn;
int nst;

double ccost(double cg, int pos)
{
    double cost = 200;
    cost += (gcap - cg)*(station[pos].price);
    if(cost - (int)cost >= 0.5) cost = (int) cost + 1;
    else cost = (int) cost;
    cost /= 100;
    return cost;
}

double opt[100][100];
int mark[100][100];

double dp(int pos, int from)
{
    if(pos>nst) return 0;
    //printf("On pos %d: %d\n", pos, mark[pos][from]);
    if(mark[pos][from]!=-1) return opt[pos][from];
    mark[pos][from] = 1;

    double sp = station[from].dio;

    double distt = station[pos].dio - sp;
    double distr;
    if(pos==nst) distr = distanc - station[pos].dio;
    else distr = station[pos+1].dio - station[pos].dio;
    double cg = gcap - distt/mpg;
    double rg = distr/mpg;
    //printf("Miles to go: %lf Required Fuel: %lf\n", distr, rg);
    //printf("Current Fuel: %lf\n", cg);

    if(cg>gcap/2){
        //printf("MORE THAN HALF\n");
        //printf("RC\n");
        if(rg>cg){
            //printf("%d %d calling %d with refill.\n", pos, from, pos+1);
            opt[pos][from] = (ccost(cg, pos)) + dp(pos+1, pos);
        }
        else{
           //printf("%d calling %d without refill.\n", from, pos+1);
           opt[pos][from] = dp(pos+1, from);
       }
    }

    else{
        //printf("LESS THAN HALF\n");
        //printf("RG: %lf CG: %lf\n", rg, cg);
        //if(rg>cg) printf("RG>CG\n");
        //printf("HERE\n");
        //printf("%d %d calling %d with refill.\n", pos, from, pos+1);
        opt[pos][from] = dp(pos+1, pos) + ccost(cg, pos);
        if(rg<=cg){
           //printf("%d calling %d without optional refill.\n", from, pos+1);
           opt[pos][from] = min(opt[pos][from], dp(pos+1, from));
       }
    }
    //printf("%d: %lf\n", pos, opt[pos][from]);
    //printf("%d %d returning %lf\n", pos, from, opt[pos][from]);
    return opt[pos][from];
}

int main(int argc, char const *argv[])
{
    Read();
    Write();
    int tc = 0;
    while(scanf("%lf", &distanc) && distanc>=0){
        MEM(mark, -1);
        scanf("%lf %lf %lf %d", &gcap, &mpg, &cost, &nst);
        //printf("HALF: %lf\n", gcap/2);
        for(int i = 1; i<=nst; i++) scanf("%lf %lf", &station[i].dio, &station[i].price);
        printf("Data Set #%d\n", ++tc);
        station[0].dio = 0;
        station[0].price = 0;
        printf("minimum cost = $%0.2lf\n", dp(1, 0) + cost);

    }


    return 0;
}
