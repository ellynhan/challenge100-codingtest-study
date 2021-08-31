#include <iostream>
#include <list>
#include <string>
#include <sstream>

using namespace std;

class ac {
public:
	list<int>inputData;
	bool isreverse = false;
	ac() {
		inputData = list<int>();
	}

	void input() {
		int size;
		cin >> size;

		string num = "";
		cin >> num;
		num.erase(num.begin());
		num.pop_back();
		istringstream ss(num);
		string stringBuffer;
		while (getline(ss, stringBuffer, ','))
			inputData.push_back(stoi(stringBuffer));
	}

	void reverse() {
		isreverse = !isreverse;
	}

	bool pop_front() {
		if (inputData.empty())
			return false;
		else {
			if (isreverse)
				inputData.pop_back();
			else
				inputData.pop_front();
		}
		return true;
	}

	friend ostream& operator <<(ostream& os, ac& data) {
		if (data.isreverse) {
			os << '[';
			if (data.inputData.size()) {
				for (list<int>::const_reverse_iterator iter = data.inputData.rbegin(); iter != --data.inputData.rend(); iter++)
					os << *iter << ',';
				os << data.inputData.front();
			}
			os << ']';
		}
		else {
			os << '[';
			if (data.inputData.size()) {
				for (list<int>::const_iterator iter = data.inputData.begin(); iter != --data.inputData.end(); iter++)
					os << *iter << ',';
				os << data.inputData.back();
			}
			os << ']';
		}
				
		
		return os;
	}

};

int main(void) {
	int n;
	cin >> n;

	ac inputData;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		inputData = ac();
		inputData.input();
		bool error = false;
		for (const char iter : str) {
			if (iter == 'R')
				inputData.reverse();
			else if (iter == 'D')
				if (!inputData.pop_front()) {
					error = true;
					cout << "error" << endl;
					break;
				}
		}
		if (!error)
			cout << inputData << endl;

	}
	return 0;
}