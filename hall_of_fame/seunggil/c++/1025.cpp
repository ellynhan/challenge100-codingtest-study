#include <iostream>
#include <set>
#include <string>
#include <cassert>
#include <cmath>
#include <vector>

using namespace std;

int row, col;

bool isValid(int x, int y) {
	if (x < 0 || x >= row || y < 0 || y >= col)
		return false;
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> row >> col;
	vector<vector<char>> inputData(row, vector<char>(col));

	set<int> answer;
	

	for (size_t i = 0; i < row; i++){
		for (size_t j = 0; j < col; j++){
			cin >> inputData[i][j];
		}
	}

	for (int rowDelta = 1; rowDelta <= row; rowDelta++) {
		for (int colDelta = 1; colDelta <= col; colDelta++) {

			for (size_t i = 0; i < row; i++) {
				for (size_t j = 0; j < col; j++) {
					int x = i;
					int y = j;
					string s;
					s.reserve(10);

					while (isValid(x, y)) {
						s.insert(s.end(), inputData[x][y]);
						answer.insert(stoi(s));
						x += rowDelta;
						y += colDelta;
					}
					answer.insert(stoi(s));
					s.clear();

					x = i;
					y = j;
					while (isValid(x, y)) {
						s.insert(s.end(), inputData[x][y]);
						answer.insert(stoi(s));
						x -= rowDelta;
						y += colDelta;
					}
					answer.insert(stoi(s));
					s.clear();


					x = i;
					y = j;
					while (isValid(x, y)) {
						s.insert(s.end(), inputData[x][y]);
						answer.insert(stoi(s));
						x += rowDelta;
						y -= colDelta;
					}
					answer.insert(stoi(s));
					s.clear();


					x = i;
					y = j;
					while (isValid(x, y)) {
						s.insert(s.end(), inputData[x][y]);
						answer.insert(stoi(s));
						x -= rowDelta;
						y -= colDelta;
					}
					answer.insert(stoi(s));
					s.clear();

					x = i;
					y = j;
					while (isValid(x, y)) {
						s.insert(s.end(), inputData[x][y]);
						answer.insert(stoi(s));
						x += rowDelta;
					}
					answer.insert(stoi(s));
					s.clear();
					

					x = i;
					y = j;
					while (isValid(x, y)) {
						s.insert(s.end(), inputData[x][y]);
						answer.insert(stoi(s));
						y += colDelta;
					}
					answer.insert(stoi(s));
					s.clear();


					x = i;
					y = j;
					while (isValid(x, y)) {
						s.insert(s.end(), inputData[x][y]);
						answer.insert(stoi(s));
						x -= rowDelta;
					}
					answer.insert(stoi(s));
					s.clear();


					x = i;
					y = j;
					while (isValid(x, y)) {
						s.insert(s.end(), inputData[x][y]);
						answer.insert(stoi(s));
						y -= colDelta;
					}
					answer.insert(stoi(s));
					s.clear();
				}
			}

		}
	}

	for (set<int>::reverse_iterator iter = answer.rbegin(); iter != answer.rend(); iter++) {
		//cout << *iter << endl;

		double a = sqrt(*iter);
		if (a == (int)a) {
			cout << *iter;
			return 0;
		}
	}

	cout << -1;

	return 0;
}