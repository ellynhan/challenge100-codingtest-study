#include <iostream>
#include <string>

using namespace std;

int main() {
	// INPUT DATA & OUTPUT DATA
	string str;
	cin >> str;
	
	for (int i = 0; i < str.length(); i++) {
		char c;
		if (str[i] <= 'C')
			c = str[i]-'A'+'X';	
		else
			c = str[i]-3;
		cout << c;
	}
}
