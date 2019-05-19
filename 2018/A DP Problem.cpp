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

int xval, val;
int globalsign;

int s2d(string x)
{
	if(x.size()==0) return 1;
	int n = 0;
	for(int i = 0; i<x.size(); i++){
		n = n*10 + x[i]-'0';
	}
	return n;
}

void parse(string token, int sign)
{
	if(token.size()==0) return;
	if(token[token.size()-1]=='x'){
		xval += (globalsign) * (sign) * s2d(token.substr(0, token.size()-1));
	}
	else val += (globalsign) * (sign) * s2d(token);
}

int main(int argc, char const *argv[])
{
	//Read();
    //Write();
    int tc;
    scanf("%d", &tc);

    TC(i, 1, tc){
    	val = 0, xval = 0, globalsign = 1;
    	string in;
    	cin>>in;
    	string tmp;
    	int sign = 1;

    	for(int i = 0; ;i++){
    		if(in[i]=='+'){
    			parse(tmp, sign);
    			sign = 1;
    			tmp.clear();	
    		}
    		else if(in[i]=='-'){
    			parse(tmp, sign);
    			tmp.clear();
    			sign = -1;
    		}
    		else if(in[i]=='='){
    			parse(tmp, sign);
    			tmp.clear();
    			sign = 1;
    			globalsign = -1;
    		}
    		else tmp += in[i];

    		if(i==in.size()-1){
    			parse(tmp, sign);
    			tmp.clear();
    			break;
    		}
    	}

    	if(xval==0 && val==0) cout<<"IDENTITY"<<endl;
    	else if(xval==0) cout<<"IMPOSSIBLE"<<endl;
    	else{
    		int ans = floor(double(-val)/xval);
    		cout<<ans<<endl;
    	}
    }
}
