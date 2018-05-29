#include <bits/stdc++.h>

using namespace std;

string mul(string n1, string n2)
{
	int r = (n1[0]-'0')*(n2[0]-'0');
	string ret = "";
	ret += (r/10) + '0';
	ret += (r%10) + '0';
	return ret;
}

string add(string n1, string n2)
{
	string result = "";
	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());
	int carry = 0;
	if(n1.size()>n2.size()) swap(n1, n2);
	for(int i = 0; i<n1.size() || i<n2.size(); i++){
		int res;
		if(i<n1.size()) res = (n1[i] - '0' + n2[i] - '0' + carry);
		else res = n2[i] - '0' + carry;
		result += (res%10) + '0';
		carry = 0;
		if(res>9) carry = 1;
	}
	
	reverse(result.begin(), result.end());
	return result;
}

string sub(string n1, string n2)
{
	string result = "";
	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());
	int carry = 0;
	for(int i = 0; i<n1.size() || i<n2.size(); i++){
		int res;
		if(i<n2.size()) res = (n1[i] - '0') - (n2[i] - '0' + carry);
		else res = (n1[i] - '0' - carry);
		carry = 0;
		if(res<0){
			res += 10;
			carry = 1;
		}
		result += res%10 + '0';
	}
	reverse(result.begin(), result.end());
	return result;
}

string karatsuba(string n1, string n2, int level)
{
	int n = max(n1.size(), n2.size());
	if(n==1) return mul(n1, n2);
	if(n%2) n += 1;

	while(n1.size()!=n) 	n1 = "0" + n1;
	while(n2.size()!=n)		n2 = "0" + n2;

	string a = n1.substr(0, n/2);
	string b = n1.substr(n/2, n-1);
	string c = n2.substr(0, n/2);
	string d = n2.substr(n/2, n-1);

	cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl;

	string p = add(a, b);
	string q = add(c, d);


	string ac = karatsuba(a, c, level+1);
	string bd = karatsuba(b, d, level+1);
	string pq = karatsuba(p, q, level+1);
	string abcd = sub(pq, add(ac, bd));
	for(int i = 0; i<n; i++) ac += '0';
	for(int i = 0; i<n/2; i++) abcd += '0';
	string result = add(ac, abcd);
	result = add(result, bd);
	return result;
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string n1, n2;
	cin>>n1>>n2;
	cout<<karatsuba(n1, n2, 1)<<endl;
}