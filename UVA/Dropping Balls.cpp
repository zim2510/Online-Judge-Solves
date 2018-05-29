#include <bits/stdc++.h>

using namespace std;

int main()
{
	int tc;
	scanf("%d", &tc);
	for(int i = 0; i<tc; i++){
		int dep, nball, result;
		scanf("%d %d", &dep, &nball);
		int lmt = pow(2, dep);
		int n = 1;
		while(n<lmt){
			if(nball%2==1) n *= 2;
			else n = n*2 + 1;
			nball = (nball+1)/2;
			if(n>=lmt) result = n/2;
		}
		cout<<result<<endl;
	}
}