#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,k;
	cin >> n >> k;
	vector<int> v;
	vector<int> ans;
	for(int i=1; i<=n; i++) {
		v.push_back(i);
	}

	int i=0;
	while(v.size()!=0) {
		i = (i+k-1)%v.size();
		ans.push_back(v[i]);
		for(int j=i; j<v.size()-1; j++) {
			v[j]=v[j+1];
		}
		v.pop_back();
 	}

	cout << "<";
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i];
		if(i!=ans.size()-1) cout << ", ";
	}
	cout << ">";
}