#include <bits/stdc++.h>

using namespace std;

int num[3] = {2, 3, 5};
vector <unsigned long long int> ugly;

void btrack(unsigned long long n, int depth)
{
	if(depth==3)
    {   ugly.push_back(n);
        //printf("%lld\n", n);
        return;
    }
	else{
		btrack(n, depth+1);
		unsigned long long x = n;
		for(int i = 0; i<40; i++){
            x *= num[depth];
			btrack(x, depth+1);
		}
	}
}

int main()
{
	btrack(1, 0);
	sort(ugly.begin(), ugly.end());
	printf("The 1500'th ugly number is %lld.\n", ugly[1499]);
}
