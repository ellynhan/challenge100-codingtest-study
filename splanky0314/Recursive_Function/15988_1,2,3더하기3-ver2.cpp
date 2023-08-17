#include <iostream>
#include <vector>
using namespace std;

int tablat[1000001]={};

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	tablat[1] = 1;
	tablat[2] = 2;
	tablat[3] = 4;

	for(int i=4; i<1000000; i++) {
		tablat[i] = (tablat[i-3]+tablat[i-2]+tablat[i-1])%1000000009;
	}
	int t, n;
	cin >> t;
	for(int i=0; i<t; i++) {
		cin >> n;
		cout << tablat[n] << "\n";
	}
}