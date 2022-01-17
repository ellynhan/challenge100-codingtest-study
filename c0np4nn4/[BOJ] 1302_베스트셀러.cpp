#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int T;
string bookName;
vector<pair<string, int>> books;
int bookCount[1000];

bool compare(const pair<string, int>& a, const pair<string, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second > b.second;
}

bool isItNewBook(string& bookName) {
	bool ret = true;
	vector<pair<string, int>>::iterator iter;
	if (!books.empty()) {
		for (iter = books.begin(); iter != books.end(); iter++) {
			if (!(*iter).first.compare(bookName)) {
				ret = false;
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	
	while (T > 0) {
		cin >> bookName;
		
		if (isItNewBook(bookName)) {
			pair<string, int> tmpBook = make_pair(bookName, 1);
			books.push_back(tmpBook);
		}
		else {
			vector<pair<string, int>>::iterator iter;
			if (!books.empty()) {
				for (iter = books.begin(); iter != books.end(); iter++) {
					if (!(*iter).first.compare(bookName)) {
						(*iter).second++;
					}	
				}
			} 
		}
		
		T--;
	}
	
	sort(books.begin(), books.end(), compare);
	cout << books[0].first << endl;
	return 0;
}
