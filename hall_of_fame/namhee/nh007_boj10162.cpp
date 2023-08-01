#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;	
	
	int numA = 0, numB = 0, numC = 0;

	if (T%10 == 0) {
		while (T > 0) {
			if (T >= 300) {
				numA += T/300;
				T -= (T/300)*300;
			}
			else if (T >= 60) {
				numB += T/60;
				T -= (T/60)*60;
			}
			else if (T >= 10) {
				numC += T/10;
				T -= (T/10)*10;
			}
		}
		cout << numA << ' ' << numB << ' ' << numC;
	}
	else
		cout << -1;

}
