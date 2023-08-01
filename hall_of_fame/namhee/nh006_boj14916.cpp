#include <iostream>

using namespace std;

bool isEven(int change);

int main() {
	// 1. INPUT DATA (change)
	int change;
	cin >> change;
	
	// 2. GET NUM OF COIN (MINIMUM)
	int minN = 0;
	if (change == 1 || change == 3) {
		minN = -1;
	} 
	else if (isEven(change)) {
		int fiveNum = change/5;
		if (!isEven(fiveNum) && fiveNum != 0)
			fiveNum--;
		minN += fiveNum;
		change -= fiveNum*5;
		
		minN += change/2;
	}
	else {
		int fiveNum = change/5;
		if (isEven(fiveNum) && fiveNum != 0)
			fiveNum--;
		minN += fiveNum;
		change -= fiveNum*5;
		
		minN += change/2;		
	}
	
	// 3. OUTPUT DATA (num of coin)
	cout << minN;
}

bool isEven(int change) {
	return change%2 == 0;
}
