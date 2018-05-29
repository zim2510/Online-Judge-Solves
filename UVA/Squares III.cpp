#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
using namespace std;

string sum(string num1, string num2, int base)
{
	string result = "";
	int mx = max(num1.size(), num2.size());
	int carry = 0;
	for(int i = 0; i<mx; i++){
		if(i<num1.size() && i<num2.size()){
			result += '0' + (num1[i]-'0'+num2[i]-'0'+carry)%base;
			carry = (num1[i]-'0'+num2[i]-'0'+carry)/base;
		}
		else if(i<num1.size()){
			result += (num1[i]-'0'+carry)%base + '0';
			carry = (num1[i]-'0'+carry)/base;
		}
		else{
			result += (num2[i]-'0'+carry)%base + '0';
			carry = (num2[i]-'0'+carry)/base;
		}
	}
	if(carry) result += '0' + carry;
	return result;
}

string multiply(string num1, string num2, int base)
{
	string init = "";
	string final = "";
	for(int i = 0; i<num1.size(); i++){
		string result = "";
		int carry = 0;
		for(int j = 0; j<num2.size(); j++){
			int res = carry + ((num1[i]-'0')*(num2[j]-'0'));
			result += '0' + (res%base);
			carry = res/base;
		}
		if(carry) result += carry + '0';
		result = init + result;
		final = sum(result, final, base);
		init += '0';
	}
	reverse(final.begin(), final.end());
	return final;
}

bool isGreater(string x, string y)
{
	if(x.size()!=y.size()) return x.size()>y.size();
	else return x>y;
}

string num2string(int num, int base)
{
	string x = "";
	while(num){
		x += '0' + (num%base);
		num /= base;
	}
	return x;
}

int main()
{
	Read();
	Write();
	printf("%c\n", '0'+85);
	string x;
	while(cin>>x){
		bool flag = 0;
		if(x=="0") break;
		for(int b = 2; b<=100; b++){
			for(int num = 1; ;num++){
				string seed = num2string(num, b);
				string res = multiply(seed, seed, b);
				if(b==88) cout<<num<<" "<<seed<<" "<<res<<endl;
				if(res==x){
					flag = 1;
					cout<<x<<" "<<b<<endl;
					break;
				}
				if(!isGreater(x, res)){
					cout<<"BALAMAR"<<endl;
					break;
				}

			}
			if(flag) break;
		}
	}
}
