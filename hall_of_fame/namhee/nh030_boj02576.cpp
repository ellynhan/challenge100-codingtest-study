#include <iostream>

using namespace std;
const int MAXNUM = 100;

int main() {
	// INPUT DATA
	int num, sum = 0, min = MAXNUM;
	for (int i = 0; i < 7; i++) {
		cin >> num;
		if (num%2 != 0) {
			sum += num;
			min = num < min ? num : min;
		}		
	}
	
	// OUTPUT DATA
	if (sum == 0) cout << -1;
	else cout << sum << endl << min;
}

