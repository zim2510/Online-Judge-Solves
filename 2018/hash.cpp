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

int baseFlag = 1;
vector <ULL> base(1, 1);
ULL BASE = 99571;

struct stringHash{

    string line;
    vector <ULL> hashed1, hashed2;

    void makeHash()
    {
        int sz = line.size();
        hashed1.resize(sz+5), hashed2.resize(sz+5);

        while(baseFlag<(sz+5)){
    		base.pb(base[baseFlag-1]*BASE);
    		baseFlag++;
    	}

        for(int i = 1; i<=sz; i++){
            hashed1[i] = hashed1[i-1]*BASE + line[i-1];
        }
        for(int i = sz; i>0; i--){
            hashed2[i] = hashed2[i+1]*BASE + line[i-1];
        }
    }

    ULL getHash()
    {
        return hashed1[line.size()];
    }
    //Returns the hash of the substring (i, j), in one based indexing
    ULL getHash(int i, int j)
    {
        //cout<<i<<" "<<j<<endl;
        return hashed1[j] - hashed1[i-1]*base[j-i+1];
    }
    //Returns the reverse hash of the substring (i, j), in one based indexing
    ULL getRHash(int i, int j)
    {
        return hashed2[i] - hashed2[j+1]*base[j-i+1];
    }
};

int main(int argc, char const *argv[])
{
	Read();
	Write();
	
	stringHash a, b;
	int n, m, q;
	cin>>n>>m>>q;
	cin>>a.line>>b.line;

	a.makeHash();
	b.makeHash();

	ULL key = b.getHash();
	cout<<key<<endl;

	vector <int> array(n+1);

	array[0] = 0;
	for(int i = 1; i<=n; i++){
		array[i] = array[i-1];
		if(a.getHash(i, i+m-1)==key){
			array[i] += 1;
		}
	}

	FOR(i, 0, q){
		int x, y;
		cin>>x>>y;
		if(y-x+1<m) printf("0\n");
		else printf("%d\n", array[y-m+1] - array[x-1]);
	}

}