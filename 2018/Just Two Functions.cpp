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

class Matrix
{
public:
	pair<LL, LL> dimension;
	vector <vector <LL> > M;

	Matrix(LL x, LL y){
		dimension = {x, y};
		M.resize(x);
		for(LL i = 0; i<x; i++) M[i].resize(y);
	}

	Matrix(const Matrix &m1, const Matrix &m2){
		dimension = {m1.dimension.ff, m2.dimension.ss};
		M.resize(m1.dimension.ff);
		for(LL i = 0; i<m1.dimension.ff; i++) M[i].resize(m2.dimension.ss);
	}
	
	void printMatrix(){
		for(LL i = 0; i<dimension.ff; i++){
			printf("%lld", M[i][0]);
			for(LL j = 1; j<dimension.ss; j++){
				printf(" %lld", M[i][j]);
			} printf("\n");
		}
	}

	void easyInput(){
		for(LL i = 0; i<dimension.ff; i++){
			for(LL j = 0; j<dimension.ss; j++){
				scanf("%lld", &M[i][j]);
			}
		}
	}
};

Matrix addMatrix(const Matrix &m1, const Matrix &m2)
{
	if(m1.dimension!=m2.dimension) return Matrix(0, 0);
	Matrix RES(m1, m2);
	for(LL i = 0; i<m1.dimension.ff; i++){
		for(LL j = 0; j<m2.dimension.ss; j++){
			RES.M[i][j] = m1.M[i][j] + m2.M[i][j];
		}
	}
	return RES;
}

Matrix multiplyMatrix(const Matrix &m1, const Matrix &m2)
{
	if(m1.dimension.ss!=m2.dimension.ff) return Matrix(0, 0);
	Matrix RES(m1, m2);

	if(rand()%2){

		for(LL i = 0; i<m1.dimension.ff; i++){
			for(LL j = 0; j<m1.dimension.ss; j++){
				for(LL k = 0; k<m2.dimension.ss; k++){
					RES.M[i][k] += m1.M[i][j] * m2.M[j][k];
				}
			}
		}
	}

	else{
		for(LL i = 0; i<m1.dimension.ss; i++){
			for(LL j = 0; j<m1.dimension.ff; j++){
				for(LL k = 0; k<m2.dimension.ss; k++){
					RES.M[j][k] += m1.M[j][i] * m2.M[i][k];
				}
			}
		}
	}

	return RES;
}

Matrix multiplyMatrix(const Matrix &m1, const Matrix &m2, LL mod)
{
	if(m1.dimension.ss!=m2.dimension.ff) return Matrix(0, 0);
	Matrix RES(m1, m2);


	for(LL i = 0; i<m1.dimension.ff; i++){
		for(LL j = 0; j<m1.dimension.ss; j++){
			for(LL k = 0; k<m2.dimension.ss; k++){
				RES.M[i][k] += m1.M[i][j] * m2.M[j][k];
				RES.M[i][k] %= mod;
			}
		}
	}


	return RES;
}

Matrix Identity(LL n)
{
	Matrix RES(n, n);
	for(LL i = 0; i<n; i++){
		RES.M[i][i] = 1;
	}
	return RES;
}

Matrix bigModMatrix(Matrix m, LL p, LL mod)
{
	if(p==0) return Identity(m.dimension.ff);
	if(p%2) return multiplyMatrix(m, bigModMatrix(m, p-1, mod), mod);
	Matrix M = bigModMatrix(m, p/2, mod);
	return multiplyMatrix(M, M, mod);
}

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    int tc;
    sf("%d", &tc);

    TC(i, 1, tc){
    	pf("Case %d:\n", i);
    	LL a[2], b[2], c[2], f[3], g[3], mod;

    	for(int i = 0; i<2; i++){
    		sf("%lld %lld %lld", &a[i], &b[i], &c[i]);
    	}

    	for(int i = 0; i<3; i++){
    		sf("%lld", &f[i]);
    	}

    	for(int i = 0; i<3; i++){
    		sf("%lld", &g[i]);
    	}

    	sf("%lld", &mod);

    	Matrix Magic(6, 6);
    	Magic.M = 	{{0, 1, 0, 0, 0, 0},
    		   		 {0, 0, 1, 0, 0, 0},
    		   		 {0, b[0], a[0], c[0], 0, 0},
    		   		 {0, 0, 0, 0, 1, 0},
    		   		 {0, 0, 0, 0, 0, 1},
    		   		 {c[1], 0, 0, 0, b[1], a[1]}};

    	Matrix I(6, 1);
    	I.M = {{f[0]}, {f[1]}, {f[2]}, {g[0]}, {g[1]}, {g[2]}};

    	int q;
    	sf("%d", &q);

    	FOR(i, 0, q){
    		long long n;
    		sf("%lld", &n);
    		Matrix res = multiplyMatrix(bigModMatrix(Magic, n, mod), I, mod);
    		printf("%lld %lld\n", res.M[0][0], res.M[3][0]);
    	}

    }
    
}
