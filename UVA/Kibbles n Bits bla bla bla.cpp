#include <bits/stdc++.h>

using namespace std;

long long convert(char *num)
{
	long long n = 0;
	int len = strlen(num);
	for(int i = 0; i<len; i++){
		if(num[i]>='0' && num[i]<='9'){
			n = n*16 + num[i] - '0';
		}
		else n = n*16 + num[i] - 'A' + 10;
	}
	//printf("%d\n", n);
	return n;
}

string d2b(long long n){
	string ret;
	while(n){
		ret += ('0' + (n%2));
		n /= 2;
	}
	for(int i = ret.size(); i<13; i++){
		ret = ret + '0';
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int tc;
	scanf("%d", &tc);
	for(int i = 1; i<=tc; i++){
		char n1[4], n2[4], sign;
		scanf(" %s %c %s", n1, &sign, n2);
		//printf("%s %c %s\n", n1, sign, n2);
		long long a, b;
		a = convert(n1);
		b = convert(n2);
		cout<<d2b(a);
		printf(" %c ", sign);
		cout<<d2b(b)<<" = ";
		if(sign=='-') printf("%lld\n", a-b);
		else printf("%lld\n", a+b);
	}
}