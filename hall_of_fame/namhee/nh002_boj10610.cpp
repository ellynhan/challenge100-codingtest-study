#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool desc (char i, char j); // for sort in descending

int main() {
	// 1. INPUT DATA(string S)
	string N;
	cin >> N;
	
	// 2. CHECK DATA - Is it possible to express multiple of 30?
	// N has a zero & N's sum of digits = mult of 3
	bool hasZero = false;
	int sumDigit = 0;
	for (int i = 0; i < N.length(); i++) {
		if (N[i] == '0')
			hasZero = true;
			
		sumDigit += N[i] - '0';
	}
	
	// 3. OUTPUT DATA(int type!!) 
	// 4. SORT : possible -> make a max multiple of 30 (Descending)
	if (hasZero && (sumDigit%3 == 0)) {
		sort(N.begin(), N.end(), desc);
		for (int i = 0; i < N.length(); i++)
			cout << (N[i]-'0');
		cout << endl;
	}
	else
		cout << -1 << endl;
}

bool desc (char i, char j) {
	return j < i;
}
