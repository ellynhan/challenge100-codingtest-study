#include <string>
#include <iostream>
#include <cassert>
#include <stack>
#include <list>
using namespace std;

void solve(string& str) {
	list<char> chars(str.begin(), str.end());

	for (list<char>::iterator iter = chars.begin(); iter != chars.end(); iter++) {
		if (*iter == '*' || *iter == '/') {
			list<char>::iterator left = iter; left--;
			if (*left == ')') {
				int count = 1;
				do {
					left--;
					if (*left == ')')
						count++;
					else if (*left == '(')
						count--;
				} while (count != 0);
			}
			
			chars.insert(left, '(');

			list<char>::iterator right = iter; right++;
			if (*right == '(') {
				int count = 1;
				do {
					right++;
					if (*right == '(')
						count++;
					else if (*right == ')')
						count--;
				} while (count != 0);
			}

			chars.insert(++right, ')');
		}
	}

	for (list<char>::iterator iter = chars.begin(); iter != chars.end(); iter++) {
		if (*iter == '+' || *iter == '-') {
			list<char>::iterator left = iter; left--;
			if (*left == ')') {
				int count = 1;
				do {
					left--;
					if (*left == ')')
						count++;
					else if (*left == '(')
						count--;
				} while (count != 0);
			}

			chars.insert(left, '(');

			list<char>::iterator right = iter; right++;
			if (*right == '(') {
				int count = 1;
				do {
					right++;
					if (*right == '(')
						count++;
					else if (*right == ')')
						count--;
				} while (count != 0);
			}

			chars.insert(++right, ')');
		}
	}

	for (list<char>::iterator iter = --chars.end(); iter != chars.begin(); iter--) {
		if (*iter == '+' || *iter == '-' || *iter == '*' || *iter == '/') {
			list<char>::iterator newPos = iter;
			int count = 0;
			do {
				newPos++;
				if (*newPos == '(')
					count++;
				else if (*newPos == ')')
					count--;
			} while (count > 0);

			chars.insert(++newPos, *iter);
			
			iter = chars.erase(iter);
			if (iter == chars.begin())
				iter++;
		}
	}


	for (char iter : chars) {
		if(iter != '(' && iter != ')')
			cout << iter;
	}
}


int main(void) {
	string inputData;

	cin >> inputData;
	solve(inputData);

	return 0;
}