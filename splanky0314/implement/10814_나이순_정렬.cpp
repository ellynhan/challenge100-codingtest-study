#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool comp(pair<int,string> a, pair<int,string> b) {
	return (a.first<b.first);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int n;
	cin >> n;
	vector<pair<int,string>> p(n);
	for(int i=0; i<n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	
	stable_sort(p.begin(), p.end(), comp);

	for(int i=0; i<n; i++) {
		cout << p[i].first << " " << p[i].second << "\n";
	}
}