#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int bookSize;
	int questSize;

	cin >> bookSize >> questSize;

	int bookNumber = 1;
	string name;
	map<int, string> bookByNum;
	map<string, int> bookByName;

	while (bookSize--) {
		cin >> name;

		bookByNum[bookNumber] = name;
		bookByName[name] = bookNumber;

		bookNumber++;
	}

	while (questSize--) {
		cin >> name;

		if (name[0] >= '0' && name[0] <= '9')
			cout << bookByNum[stoi(name)] << '\n';
		else
			cout << bookByName[name] << '\n';
	}

	return 0;
}