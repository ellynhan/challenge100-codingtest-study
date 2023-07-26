// Basic Greedy Algorithm : BOJ 5585
#include <iostream>

using namespace std;

int main() {
	// 1. INPUT DATA(price)
	int price;
	cin >> price;
	
	// 2. GET CHANGE
	int change = 1000 - price;
	
	// 3. GET CHANGE'S NUM (minimum)
	int changeNum = 0;
	while (change > 0) {
		if (change >= 500) {
			changeNum += change/500;
			change -= (change/500)*500;
		}
		else if (change >= 100) {
			changeNum += change/100;
			change -= (change/100)*100;
		}
		else if (change >= 50) {
			changeNum += change/50;
			change -= (change/50)*50;
		}
		else if (change >= 10) {
			changeNum += change/10;
			change -= (change/10)*10;
		}
		else if (change >= 5) {
			changeNum += change/5;
			change -= (change/5)*5;
		}
		else if (change >= 1) {
			changeNum += change/1;
			change -= (change/1)*1;
		}
	}
	
	// 4. OUTPUT DATA(num of change)
	cout << changeNum << endl;
}
