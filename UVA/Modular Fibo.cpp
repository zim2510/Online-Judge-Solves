#include <bits/stdc++.h>

using namespace std;

struct Matrix{ long long mat[2][2]; };

Matrix identity;
int mod;

Matrix multiply(Matrix x, Matrix y)
{
	Matrix ans;
	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; j++){
			for(int k = ans.mat[i][j] = 0; k<2; k++){
				ans.mat[i][j] = (ans.mat[i][j] + x.mat[i][k] * y.mat[k][j])%mod;
			}
		}
	}
	return ans;
}


Matrix bigMod(Matrix base, int p)
{
	
	if(p==0) return identity;
	if(p%2==1) return multiply(base, bigMod(base, p-1));
	Matrix x = bigMod(base, p/2);
	return multiply(x, x);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; j++){
			identity.mat[i][j] = (i==j);
		}
	}

	Matrix base;
	base.mat[0][0] = base.mat[0][1] = base.mat[1][0] = 1;
	base.mat[1][1] = 0;

	int n, m;
	while(scanf("%d %d", &n, &m)==2){
		mod = 1<<m;
		Matrix ans = bigMod(base, n);
		printf("%d\n", ans.mat[0][1]);
	}
}