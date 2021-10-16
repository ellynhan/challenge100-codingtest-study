#include <iostream>
#include <string>

using namespace std;

int main() {
	// 1. INPUT DATA
	string str;
	cin >> str;
	
	// 2. GET VALUE (get capital letter)
	string abbr;
	for (long unsigned int i = 0; i < str.size(); i++)
		if ('A' <= str[i] && str[i] <= 'Z')
			abbr.push_back(str[i]);
	
	// 3. OUTPUT DATA
	cout << abbr;
}
