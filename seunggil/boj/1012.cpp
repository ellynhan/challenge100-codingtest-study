#include <iostream>
#include <vector>

using namespace std;

int row = 0;
int column = 0;

bool checkValid(const vector<vector<bool>>& info, int x, int y) {
	if (x < 0 || x >= row)
		return false;
	if (y < 0 || y >= column)
		return false;

	return info[x][y];
}

void checkpos(vector<vector<bool>>& info, int currentX, int currentY) {
	info[currentX][currentY] = false;
	// cout << "delete :" << currentX << " " << currentY << endl;
	int x = currentX;
	int y = currentY + 1;

	if (checkValid(info, x, y))
		checkpos(info, x, y);
	
	x = currentX + 1;
	y = currentY;

	if (checkValid(info, x, y))
		checkpos(info, x, y);

	x = currentX - 1;
	y = currentY;

	if (checkValid(info, x, y))
		checkpos(info, x, y);

	x = currentX;
	y = currentY - 1;

	if (checkValid(info, x, y))
		checkpos(info, x, y);

}

int main(void) {
	vector<vector<bool>> inputData;
	int count;
	cin >> count;

	while (count-- > 0) {
		int answer = 0;
		int x, y, n;
		cin >> x >> y >> n;

		inputData = vector<vector<bool>>(x);
		for (vector<bool>& iter : inputData)
			iter = vector<bool>(y);
		
		row = x;
		column = y;

		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			inputData[x][y] = true;
		}
		//for (int i = 0; i < row; i++) {
		//	for (int j = 0; j < column; j++)
		//		cout << inputData[i][j] << " ";
		//	cout << endl;
		//}
			
		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++)
				if (inputData[i][j]){
					answer++;
					checkpos(inputData, i, j);
				}
					
		cout << answer << endl;
	}

	return 0;
}