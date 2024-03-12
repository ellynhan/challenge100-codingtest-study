#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	string s;
	vector<int> v;
	cin >> s;
	for(int i=0; i<s.length(); i++) {
		v.push_back(int(s[i])-'0');
	}

	int maxindex;
	for(int i=0; i<s.length()-1; i++) {
		maxindex = i;
		for(int j=i+1; j<s.length(); j++) {
			if(v[maxindex]<v[j]) {
				maxindex = j;
			}
		}
		swap(v[i], v[maxindex]);
	}

	for(int i=0; i<v.size(); i++) {
		cout << v[i];
	}
}