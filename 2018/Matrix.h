#include <bits/stdc++.h>
#define ff first 
#define ss second

using namespace std;

class Matrix
{
public:
	pair<int, int> dimension;
	vector <vector <int> > M;

	Matrix(int x, int y){
		M.resize(x);
		for(int i = 0; i<x; i++) M[i].resize(y);
	}
	Matrix(Matrix &m1, Matrix &m2){
		M.resize(m1.dimension.ff);
		for(int i = 0; i<m1.dimension.ff; i++) M[i].resize(m2.dimension.ss);
	}
	
	void printMatrix(){
		for(int i = 0; i<dimension.ff; i++){
			for(int j = 0; j<dimension.ss; i++){
				printf("%d ", M[i][j]);
			} printf("\n");
		}
	}
};

Matrix add(Matrix &m1, Matrix &m2)
{
	if(m1.dimension!=m2.dimension) return Matrix(0, 0);
	Matrix M(m1, m2);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	Matrix m1(2, 2);
	Matrix m2(2, 2);

	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; i++){
				scanf("%d", &m1.M[i][j]);
		}
	}

	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; i++){
				scanf("%d", &m2.M[i][j]);
		}
	}


}