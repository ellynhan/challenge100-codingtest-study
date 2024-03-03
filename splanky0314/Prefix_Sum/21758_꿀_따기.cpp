#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int n;
	long long sum=0, maxsum=-1, max=-1;
	cin >> n;
	vector<int> v(n);
	vector<int> s(n,0);
	vector<int> m;
	cin >> v[0];
	s[0]=v[0];
	for(int i=1; i<n; i++) {
		cin >> v[i];
		s[i]=s[i-1]+v[i];
		if(v[i]>max) {
			max=v[i];
			m.push_back(i);
		}
	}

	// i=n-1에 벌통
	for(int i=1; i<n-1; i++) {
		sum=2*s[n-1]-s[0]-s[i]-v[i];
		if(maxsum<sum) maxsum = sum;
	}

	// i=0에 벌통
	for(int i=n-2; i>=1; i--) {
		sum=2*s[n-1]-v[n-1]-v[i]-(s[n-1]-s[i-1]);
		if(maxsum<sum) maxsum = sum;
	}

	// 중간에 벌통
	while(m.size()) {
		int tar = m.back();
		for(int i=1; i<n; i++) {
			if(i==tar) continue;
			else if(tar<i) {
				sum=(s[tar]-s[0])+((s[n-1]-s[tar-1])-v[i]);
			}
			
			if(maxsum<sum) maxsum = sum;
		}
		m.pop_back();
	}

	cout << maxsum;	
}