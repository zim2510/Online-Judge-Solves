#include <bits/stdc++.h>

using namespace std;

int c2p(int x)
{
	int total = 0;
	total += min(200, x) / 2;
	x -= min(200, x);
	if(x>0){
		total += min(3*(10000-100), x)/3;
	}
	x -= min(3*(10000-100), x);
	if(x>0){
		total += min(5*(1000000-10000), x)/5;
	} 
	x -= min(5*(1000000-10000), x);
	if(x>0) total += x/7;
	return total;
}

int p2c(int x)
{
	int total = 0;
	total += min(100, x) * 2;
	x -= min(100, x);
	if(x>0){
		total += min(10000-100, x) * 3;
	}
	x -= min(10000-100, x);
	if(x>0){
		total += min(1000000-10000, x) * 5; 
	}
	x-= min(1000000-10000, x);
	total += x*7;
	return total;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	int a, b;
	while(scanf("%d %d", &a, &b) && (a||b)){
		int total = c2p(a), ans;
		int hi = total/2;
		int lo = 0;
		while(1){
			int mid = (hi+lo)/2;
			if(p2c(total-mid) - p2c(mid) == b){
				ans = mid;
				break;
			}
			else if(p2c(total-mid) - p2c(mid) > b){
				lo = mid+1;
			}
			else{
				hi = mid-1;
			}
		}
		cout<<p2c(ans)<<endl;
	}
}