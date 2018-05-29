#include <stdio.h>
#include <vector>
#include <map>
#include <iostream>
 
using namespace std;
 
vector<string> name;
map<string, int> index;
 
int base[10000], CD[10000], D[10000], ub[1000][10], lb[1000][10], ix[1000], c[1000];
 
int ccalc(int index, int use)
{
	if(index==D[use]) return CD[use];
	c[index] = ccalc(index+1, use)*(ub[use][index] - lb[use][index] +1);
	return c[index];
}
 
int main()
{
	int n, r;
 
	scanf("%d %d", &n, &r);
 
	for(int i = 0; i<n; i++){
		string in;
		cin>>in;
		index[in] = i;
		name.push_back(in);
 
		scanf("%d %d %d", &base[i], &CD[i], &D[i]);
 
		for(int j = 0; j<D[i];j++){
			scanf("%d %d", &lb[i][j], &ub[i][j]);
		}
	}
 
	for(int i = 0; i<r; i++){
		string in;
		cin>>in;
		int use = index[in];
		for(int j = 0; j<D[use]; j++){
			scanf("%d", &ix[j]);
		}
		ccalc(1, use);
		c[0] = base[use];
        int z;
		for(z = 0; z<D[use]-1; z++){
            c[0] -= c[z+1]*lb[use][z];
		}
		c[0] -= CD[use]*lb[use][z];
        //printf("C0: %d\n", c[0]);
		int p = 0;
		for(z = 0; z<D[use]-1; z++){
            p += c[z+1]*ix[z];
		}
        p += CD[use] * ix[z];
		int out = c[0] + p;
		cout<<name[use];
        printf("[");
        for(int i = 1; i<=D[use]; i++){
            printf("%d", ix[i-1]);
            if(i!=D[use]) printf(", ");
        }
		printf("] = %d\n", out);
	}
}