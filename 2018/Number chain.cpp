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


int s2d(string x)
{
	if(x.size()==0) return 1;
	int n = 0;
	for(int i = 0; i<x.size(); i++){
		n = n*10 + x[i]-'0';
	}
	return n;
}

string num2string(int num, int base)
{
	string x = "";
	while(num){
		x += '0' + (num%base);
		num /= base;
	}
	reverse(x.begin(), x.end());
	if(!x.size()) return "0";
	else return x;
}

int main(int argc, char const *argv[])
{
	//Read();
    //Write();
    
    string in;
    while(cin>>in){
    	if(in=="0") break;
    	cout<<"Original number was "<<in<<endl;
    	map <string, bool> m;
    	int length = 0;
    	while(true){
    		length++;
	    	string n = in;
	    	sort(n.begin(), n.end());
	    	string r = n;
	    	reverse(r.begin(), r.end());
	    	in = num2string(s2d(r) - s2d(n), 10);
	    	cout<<s2d(r)<<" - "<<s2d(n)<<" = "<<s2d(in)<<endl;
	    	if(m[in]) break;
	    	else m[in] = 1;
	    }
	    cout<<"Chain length "<<length<<endl<<endl;
    }
}
