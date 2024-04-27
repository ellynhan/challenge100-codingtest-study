#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	int N{};
	cin >> N;

	set<string, greater<string>> s;
	for (int i = 0; i < N; i++) {
		string str, type;
		cin >> str >> type;
		if (type == "enter") {
			s.insert(str);
		}
		else if (type == "leave") {
			s.erase(str);
		}
	}

	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << "\n";
	}
	

	return 0;
}
