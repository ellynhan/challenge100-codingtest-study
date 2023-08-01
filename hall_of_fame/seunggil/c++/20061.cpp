#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


vector<vector<bool>> puzzle(10, vector<bool>(10));
int score = 0;

inline bool validRange(int x, int y) {
	return (0 <= x && x <= 9 && 0 <= y && y <= 9);
}

void putToBluePuzzle(int x1, int y1, int x2, int y2);
void putToGreenPuzzle(int x1, int y1, int x2, int y2);
void putToBluePuzzle(int x, int y);
void putToGreenPuzzle(int x, int y);
void getBluePuzzleScore();
void getGreenPuzzleScore();

void moverightBluePuzzle();
void movedownGreenPuzzle();

void print() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i >= 4 && j >= 4)
				break;
			cout << puzzle[i][j] << ' ';
		}cout << '\n';
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int type, x, y;
		cin >> type >> x >> y;

		switch (type)
		{
		case 1:
			putToBluePuzzle(x, y);
			putToGreenPuzzle(x, y);
			break;
		case 2:
			putToBluePuzzle(x, y, x, y+1);
			putToGreenPuzzle(x, y, x, y + 1);
			break;
		case 3:
			putToBluePuzzle(x, y, x + 1, y);
			putToGreenPuzzle(x, y, x + 1, y);
			break;
		default:
			assert(false);
			break;
		}

		getBluePuzzleScore();
		getGreenPuzzleScore();

		for (int i = 0; i < 4; i++) {
			for (int j = 4; j < 6; j++) {
				if(puzzle[i][j])
					moverightBluePuzzle();
			}
		}

		for (int i = 4; i < 6; i++) {
			for (int j = 0; j < 4; j++) {
				if (puzzle[i][j])
					movedownGreenPuzzle();
			}
		}

		//print();
	}

	int count = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (puzzle[i][j])
				count++;
		}
	}
	cout << score << '\n' << count;

	return 0;
}

void putToBluePuzzle(int x1, int y1, int x2, int y2) {
	if (x1 == x2) {
		while (validRange(x2, y2 + 1) && !puzzle[x2][y2 + 1]) {
			y1++;
			y2++;
		}
	}
	else {
		while (validRange(x1, y1 + 1) && validRange(x2, y2 + 1) && !puzzle[x1][y1 + 1] && !puzzle[x2][y2 + 1]) {
			y1++;
			y2++;
		}
	}
	

	puzzle[x1][y1]= true;
	puzzle[x2][y2] = true;
}

void putToGreenPuzzle(int x1, int y1, int x2, int y2) {
	if (x1 != x2) {
		while (validRange(x2 + 1, y2) && !puzzle[x2 + 1][y2]) {
			x1++;
			x2++;
		}
	}
	else {
		while (validRange(x1 + 1, y1) && validRange(x2 + 1, y2) && !puzzle[x1 + 1][y1] && !puzzle[x2 + 1][y2]) {
			x1++;
			x2++;
		}
	}


	puzzle[x1][y1] = true;
	puzzle[x2][y2] = true;
}

void putToBluePuzzle(int x, int y) {
	while (validRange(x, y + 1) && !puzzle[x][y + 1]) {
		y++;
	}
	puzzle[x][y] = true;
}

void putToGreenPuzzle(int x, int y) {
	while (validRange(x + 1, y) && !puzzle[x + 1][y]) {
		x++;
	}
	puzzle[x][y] = true;
}


void getBluePuzzleScore() {
	for(int j = 9; j >= 4; j--) {
		bool result = true;
		for (int i = 3; i >= 0; i--) {
			if (!puzzle[i][j]) {
				result = false;
				break;
			}

		}
		// 해당 열 삭제
		if (result) {
			score++;
			for (int y = j; y >= 4; y--) {
				for (int x = 3; x >= 0; x--) {
					puzzle[x][y] = puzzle[x][y-1];
				}
			}
			j++;
		}
	}
	
}
void getGreenPuzzleScore() {
	for (int i = 9; i >= 4; i--) {
		bool result = true;
		for (int j = 0; j <= 3; j++) {
			if (!puzzle[i][j]) {
				result = false;
				break;
			}
		}

		// 해당 행 삭제
		if (result) {
			score++;
			for (int x = i; x >= 4; x--) {
				for (int y = 0; y < 4; y++) {
					puzzle[x][y] = puzzle[x - 1][y];
				}
			}
			i++;
		}
	}
}

void moverightBluePuzzle() {
	for (int i = 0; i < 4; i++) {
		for (int j = 9; j >= 4; j--) {
			puzzle[i][j] = puzzle[i][j - 1];
		}
	}
}
void movedownGreenPuzzle() {
	for (int i = 9; i >= 4; i--) {
		for (int j = 0; j < 4; j++) {
			puzzle[i][j] = puzzle[i - 1][j];
		}
	}
}
