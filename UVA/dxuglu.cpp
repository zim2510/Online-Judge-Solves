#include<bits/stdc++.h>
using namespace std;

 
void solve(){
	vector<unsigned long long>v;
	vector<unsigned long long>ans;
	int ct=1500;
	v.push_back(1);
	ans.push_back(1);
	while(ct--){
		int x=v.front();
		v.push_back(x*2);
		v.push_back(x*3);
		v.push_back(x*5);
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		int y=v.front();
		ans.push_back(y);
		v.erase(v.begin());

	}
	cout<<v.front()<<endl;
	


}
int main(){
	solve();
}