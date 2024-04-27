#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		string str{};
		cin >> str;
		list<char> answer;
		list<char>::iterator it = answer.begin();
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '<') {
				if (it != answer.begin()) it--;
			}
			else if (str[i] == '>') {
				if (it != answer.end()) it++;
			}
			else if (str[i] == '-') {
				if (it != answer.begin()) {
					it = answer.erase(--it);
				}
			}
			else {
				answer.insert(it, str[i]);
			}
		}

		for (auto iter = answer.begin(); iter != answer.end(); iter++) cout << *iter;
		cout << "\n";
	}
	return 0;
}
