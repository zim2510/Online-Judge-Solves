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

int main(int argc, char const *argv[])
{
    //Read();
    //Write();
    int r, c;
    while(scanf("%d %d", &r, &c) && (r+c)){
        int grid[r][c];
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                scanf("%d", &grid[i][j]);
            }
        }


        int q;
        scanf("%d", &q);
        while(q--){
            int s, e, ans = 0;
            scanf("%d %d", &s, &e);
            for(int i = 0; i<r; i++){
                if(grid[i][0]<=e && grid[i][c-1]>=s){
                    int j = lower_bound(&grid[i][0], &grid[i][0]+c, s) - &grid[i][0];
                    //cout<<"IJ"<<" "<<i<<" "<<j<<endl;
                    if(j<c){
                        int lo = 0, hi = min(c-j-1, r-i-1);
                        //cout<<"LH"<<lo<<" "<<hi<<endl;
                        while(lo<=hi){
                            int mid = (lo+hi)/2;
                            if(grid[i+mid][j+mid]<=e){
                                lo = mid + 1;
                                if(mid+1>ans) ans = mid + 1;
                            }
                            else hi = mid - 1;
                        }
                        //cout<<ans<<endl;
                    }
                }
            }
            cout<<ans<<endl;
        }
        cout<<"-"<<endl;
    }
}
