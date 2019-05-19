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
#define sf             	  scanf
#define pf 	              printf

const int dx[] = { 0, -1,  0,  1,		 -1,  1,  1, -1,     -2, -2,  2,  2, -1, -1,  1,  1};
const int dy[] = {-1,  0,  1,  0,		  1,  1, -1, -1,     -1,  1, -1,  1, -2,  2, -2,  2};

using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

int main()
{
    //Read();
    //Write();

    int n;
    
    vector <int> nums;
    while(scanf("%d", &n)==1){
        if(!n){
            if(nums.size()==0) continue;
            double upcount = 0, downcount = 0;
            int upo = 0, doo = 0;
            int undecided = 0;
            int upflag = 0, downflag = 0, uflag = 0;

            for(int i = 1; i<nums.size(); i++){
                //printf("%d %d %lf %lf\n", nums[i], nums[i-1], upcount, downcount);
                if(nums[i]>nums[i-1]){
                   // printf("TRUE\n");
                    if(upflag) upcount+=1;
                    else if(uflag){
                        upo++;
                        uflag = 0;
                        upflag = 1;
                        upcount += undecided + 1;
                        undecided = 0;
                    }
                    else if(downflag){
                        downflag = 0;
                        upo++;
                        upflag = 1;
                        upcount+=1;
                    }
                    else{
                        upflag = 1;
                        upo++;
                        upcount += 1;
                    }
                }

                else if(nums[i]<nums[i-1]){
                    if(downflag) downcount+=1;
                    else if(uflag){
                        doo++;
                        uflag = 0;
                        downflag = 1;
                        downcount += undecided + 1;
                        undecided = 0;
                    }
                    else if(upflag){
                        upflag = 0;
                        doo++;
                        downflag = 1;
                        downcount+=1;
                    }
                    else{
                        downflag = 1;
                        doo++;
                        downcount += 1;
                    }
                }

                if(nums[i]==nums[i-1]){
                    if(uflag) undecided+=1;
                    else if(upflag){
                        upcount += 1;
                    }
                    else if(downflag){
                        downcount += 1;
                    }
                    else{
                        uflag = 1;
                        undecided++;
                    }
                }
            }
            printf("Nr values = %d: ", nums.size());
            printf(" %f %f\n", upo?upcount/upo:0, doo?downcount/doo:0);
            nums.clear();
        }
        else{
            nums.pb(n);
        }
    }

}