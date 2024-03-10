#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int,int>> v;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int n, tmp;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> tmp;
		v.push_back({tmp, i});
	}

	sort(v.begin(), v.end());

	// for(vector<pair<int,int>>::iterator it = v.begin(); it!=v.end(); it++) {
	// 	cout << it->first << "," << it->second << " ";
	// } cout << endl;

	int maxval = 0;
	for(int i=0; i<n; i++) {
		if(maxval < v[i].second - i) {
			maxval = v[i].second - i;
		}
	}

	cout << maxval+1;
}