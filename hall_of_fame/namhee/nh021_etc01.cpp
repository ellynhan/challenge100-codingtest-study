#include <iostream>
#include <algorithm>

using namespace std;

const int TEAM = 50001;
int w[TEAM];

int main() {
	int n;
	cin >> n;
	
	for(int i = 0; i < 2*n; i++)
		cin >> w[i];
		
	sort(w, w+2*n);
	
	int S = 200001;
	for(int i = 0; i < n; i++)
		S = min(S, w[i]+w[2*n-i-1]);
	
	cout << S;
}
