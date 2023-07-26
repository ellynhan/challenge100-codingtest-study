#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	// 1. INPUT DATA
	string str;
	cin >> str;
	int len = str.size();
	
	// 2. GET VALUE
	int digits = 0;
	for (int i = 1; i <= len; i++) {
		if (i == len) {
			if (i == 1)
				digits += (str[0]-'0')*i;
			else
				digits += (stoi(str)-pow(10, i-1)+1)*i;
		}
		else 
			digits += (pow(10, i)-pow(10, i-1))*i;
	}
	
	// 3. OUTPUT DATA
	cout << digits;
}
