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

using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

vector <string> ins;
int isThere[256], start[256];
vector <char> letters;
int sol, n, mx;
int mark[10];

LL convert(string x)
{
	LL result = 0;
	for(int i = 0; i<x.size(); i++){
		result = result*10 + isThere[x[i]];
	}
	return result;
}

void print()
{
    for(int i = 0; i<letters.size(); i++){
        printf("%c: %d\n", letters[i], isThere[letters[i]]);
    }
    printf("\n\n");
}

void btrack(int ci)
{
	if(ci==letters.size()){
        int carry = 0;
		for(int i = 0; i<mx; i++){
            int sum = 0;
            for(int j = 0; j<n-1; j++){
                if(i<=ins[j].size()){
                    sum += isThere[ins[j][i]];
                }
            }
            sum += carry;
            carry = sum/10;
            sum %= 10;
            if(sum!=isThere[ins[n-1][i]]) return;
		}
		if(!carry) print();
		if(!carry) sol++;
		return;
	}

	for(int i = start[letters[ci]]; i<10; i++){
		if(!mark[i]){
			mark[i] = 1;
			isThere[letters[ci]] = i;
			btrack(ci+1);
			mark[i] = 0;
		}
	}

}
int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	ios_base::sync_with_stdio(false);
	while(cin>>n){
		MEM(isThere, 0);
		MEM(start, 0);
		ins.clear();
		letters.clear();
        mx = 0;

		for(int i = 0; i<n; i++){
            string in;
            cin>>in;
            ins.pb(in);
            for(int j = 0; j<ins[i].size(); j++){
                if(isThere[ins[i][j]]==0){
                    isThere[ins[i][j]] = -1;
                    letters.pb(ins[i][j]);
                    if(j==0) start[ins[i][j]] = 1;
                    else start[ins[i][j]] = 0;
                }
            }
            mx = 0;
            //ins[i].size();
            mx = max(mx, (int)in.size());
            reverse(ins[i].begin(), ins[i].end());
		}
		sol = 0;
		btrack(0);
		cout<<sol<<endl;
	}
}
