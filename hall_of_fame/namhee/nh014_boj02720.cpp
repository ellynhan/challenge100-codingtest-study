#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		// 1. INPUT DATA(change)
		int change;
		cin >> change;
		
		// 2. GET CHANGE'S NUM (minimum)
		int quarter = 0, dime = 0, nickel = 0, penny = 0;
		while (change > 0) {
			if (change >= 25) {
				quarter += change/25;
				change -= quarter*25;
			}
			else if (change >= 10) {
				dime += change/10;
				change -= dime*10;
			}
			else if (change >= 5) {
				nickel += change/5;
				change -= nickel*5;
			}
			else if (change >= 1) {
				penny += change;
				change -= penny;
			}
		}
		
		// 3. OUTPUT DATA(num of change)
		cout << quarter << ' ' << dime << ' ' << nickel << ' ' << penny << endl;
	}
}
