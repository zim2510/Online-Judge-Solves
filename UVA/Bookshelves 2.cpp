#include <bits/stdc++.h>
#define PQ priority_queue
using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	vector <int> s1(n), s2(n);
	
	int temp;

	for(int i = 0; i<n; i++) cin>>s1[i];
	for(int i = 0; i<n; i++) cin>>s2[i];
	PQ <int, vector<int>, greater<int> > s1s(s1.begin(), s1.end());
	PQ <int, vector<int> > s1b(s1.begin(), s1.end());
	PQ <int, vector<int>, greater<int> > s2s(s2.begin(), s2.end());
	PQ <int, vector<int> > s2b(s2.begin(), s2.end());
	
	int mn = (s1b.top() + s2b.top());

	for(int i = 0; i<k; i++){
		int mx1 = s1b.top();
		int mx2 = s2b.top();
		s1b.pop();
		s2b.pop();

		int mn1 = s1s.top();
		int mn2 = s2s.top();
		s1s.pop();
		s2s.pop();

		cout<<mx1<<" "<<mn1<<" "<<mx2<<" "<<mn2<<endl;
		cout<<max(mx1, mx2) + max(mn2, s1b.top())<<endl;
		cout<<max(mx1, mx2) + max(mn1, s2b.top())<<endl;

		if(max(mx1, mx2) + max(mn2, s1b.top())<max(mx1, mx2) + max(mn1, s2b.top())){
			s2b.push(mx1);
			s2s.push(mx1);
			s2b.push(mx2);

			s1s.push(mn2);
			s1b.push(mn2);
			s1s.push(mn1);
		}

		else{
			s1b.push(mx2);
			s1s.push(mx2);
			s1b.push(mx1);

			s2s.push(mn1);
			s2b.push(mn1);
			s2s.push(mn2);
		}

		if(s1b.top()+s2b.top()<mn) mn = s1b.top() + s2b.top();
	}

	cout<<mn<<endl;
	
}