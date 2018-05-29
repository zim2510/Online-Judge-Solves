#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define TC(i, a, b)       for(int i = a; i<=b; i++)
#define FOR(i, a, b)      for(int i = a; i<b; i++)
#define ROF(i, a, b)      for(int i = a; i>=b; i--)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)            ((x)*(x))
#define valid(x, s, e)    (x>=s && x<=e)
#define sz(a)             int((a).size())
#define all(c)            (c).begin(),(c).end()
#define tr(c,i)           for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)      ((c).find(x) != (c).end())
#define cpresent(c,x)     (find(all(c),x) != (c).end())
#define pb                push_back
#define MAX               1000000000
#define ff                first
#define ss                second

using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

int mx, lmt, switches, lights, s[1005], light[1005];

void ektuhelp(int ci)
{
    if(ci==switches){
        int t = 0;
        TC(i, 1, lights) t += light[i];
        if(t>mx) mx = t;
        return;
    }
    int cnt = 0;
    for(int i = s[ci]; i<=lights; i+=s[ci]){
        light[i] = !light[i];
        if(light[i]) cnt++;
        else cnt--;
    }
    if(cnt>0) ektuhelp(ci+1);
    for(int i = s[ci]; i<=lights; i+=s[ci]){
        light[i] = !light[i];
    }
    if(cnt<=0) ektuhelp(ci+1);
}

void resultde(int ci)
{
    if(ci==switches){
        int t = 0;
        TC(i, 1, lights) t += light[i];
        if(t>mx) mx = t;
        return;
    }

    if(s[ci]*s[ci]>lights){
        lmt = ci;
        ektuhelp(ci);
        return;
    }

    resultde(ci+1);
    for(int i = s[ci]; i<=lights; i+=s[ci]){
        light[i] = !light[i];
    }

    resultde(ci+1);
    for(int i = s[ci]; i<=lights; i+=s[ci]){
        light[i] = !light[i];
    }
}

int main(int argc, char const *argv[])
{
    //Read();
    int tc;
    scanf("%d", &tc);
    TC(i, 1, tc){
        scanf("%d %d", &lights, &switches);
        FOR(i, 0, switches){
            scanf("%d", &s[i]);
        }
        sort(s, s+switches);
        mx = 0;
        resultde(0);
        printf("Case #%d: %d\n", i, mx);
    }
}
