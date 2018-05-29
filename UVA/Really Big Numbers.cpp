#include <bits/stdc++.h>
#define LL long long
using namespace std;

bool valid(LL num, LL x)
{
	int sum = 0;
	LL temp = num;
	while(temp){
		sum += temp%10;
		temp /= 10;
	}
	return (num-sum)>=x;
}

LL lbound(LL x, LL hi)
{
	LL lo = 0, ans = hi + 1, mid;
	while(lo<=hi){
		mid = (lo+hi)/2;
		if(valid(mid, x)){
			ans = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	return ans;
}

int main()
{
	LL hi, lo = 0, mid;
	LL x;
	scanf("%lld %lld", &hi, &x);
	LL u = hi;
	LL l = lbound(x, hi);
	cout<<u-l+1<<endl;
}
