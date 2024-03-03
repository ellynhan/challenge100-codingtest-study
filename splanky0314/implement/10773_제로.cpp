#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int k, tmp;
	ll sum=0;
	cin >> k;
	vector<int> v;
	for(int i=0; i<k; i++) {
		cin >> tmp;
		if(tmp==0) {
			sum -= v[v.size()-1];
			v.pop_back();
		}
		else {
			v.push_back(tmp);
			sum += tmp;
		}
	}

	cout << sum;
}