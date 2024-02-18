#include <iostream>
#include <vector>
using namespace std;

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

	for(int i=n-1; i>0; i--) {
		for(int j=0; j<i; j++) {
			if(v[j]>v[j+1]) {
				int tmp = v[j];
				v[j] = v[j+1];
				v[j+1] = tmp;
			}
		}
	}

	for(int i=0; i<n; i++) {
		cout << v[i] << "\n";
	}
}