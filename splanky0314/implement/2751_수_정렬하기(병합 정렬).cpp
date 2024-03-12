#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

// 시간 초과 나는 답안임!

vector<int> merge(vector<int> v1, vector<int> v2) {
	vector<int> result;
	while(!v1.empty() && !v2.empty()) {
		if(v1[0]<=v2[0]) {
			result.push_back(v1[0]);
			v1.erase(v1.begin());
		}
		else {
			result.push_back(v2[0]);
			v2.erase(v2.begin());
		}
	}
	if(!v1.empty()) {
		for(int i=0; i<v1.size(); i++) {
			result.push_back(v1[i]);
		}
	}
	if(!v2.empty()) {
		for(int i=0; i<v2.size(); i++) {
			result.push_back(v2[i]);
		}
	}

	return result;
}

vector<int> devide(vector<int> v) {
	if(v.size()==1) return v;

	vector<int> v1;
	vector<int> v2;

	int mid = v.size()/2;
	for(int i=0; i<mid; i++) {
		v1.push_back(v[i]);
	}
	for(int i=mid; i<v.size(); i++) {
		v2.push_back(v[i]);
	}

	return merge(devide(v1), devide(v2));
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, tmp;
	vector<int> v;
	
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	vector<int> ans = devide(v);

	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << "\n";
	}
}