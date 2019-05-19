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

int main(int argc, char const *argv[])
{
	//Read();
    //Write();
    
    int tc;
    sf("%d", &tc);
    getchar();
    getchar();


    int pr[256];
    pr['+'] = 1;
    pr['-'] = 1;
    pr['*'] = 2;
    pr['/'] = 2;
    pr['('] = 3;

    FOR(i, 0, tc){
    	stack <char> s;
        if(i) cout<<endl;
    	while(true){
    	
    		char ch;
    		int x = sf("%c", &ch);


    		if(ch=='\n' || x!=1){
    			while(!s.empty()) { cout<<s.top(); s.pop(); }
                cout<<endl;
    			break;
    		}

            getchar();

    		if(valid(ch, '0', '9')) pf("%c", ch);

    		else{
    			if(ch==')'){
    				while(s.top()!='('){
    					cout<<s.top();
    					s.pop();
    				}
    				s.pop();
    			}
    			else{
    				while(s.size() && pr[s.top()]>=pr[ch]){
    					if(s.top()=='(') break;
    					cout<<s.top();
    					s.pop();
    				}
    				s.push(ch);
    			}
    		}
    	}
    }
}
