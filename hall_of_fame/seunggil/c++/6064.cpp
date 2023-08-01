#include <iostream>
#include <vector>

using namespace std;

int gcd(int x, int y) {
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		int maxX, maxY, x, y;
		cin >> maxX >> maxY >> x >> y;

		int range = gcd(maxX, maxY);
		range = (maxX * maxY / range);
		int rangeX = range / maxX;
		int rangeY = range / maxY;
		vector<int> result1;
		vector<int> result2;
		result1.reserve(rangeX);
		result2.reserve(rangeY);
		for (int j = 0; j < (rangeX); j++)
			result1.push_back(maxX * j + x);
		for (int j = 0; j < (rangeY); j++)
			result2.push_back(maxY * j + y);
		
		int answer = -1;

		vector<int>::iterator iter1 = result1.begin();
		vector<int>::iterator iter2 = result2.begin();

		while (iter1 != result1.end() && iter2 != result2.end()) {
			if (*iter1 == *iter2) {
				answer = *iter1;
				break;
			}
			else if (*iter1 > *iter2)
				iter2++;
			else
				iter1++;
		}
		cout << answer << '\n';
	}


	return 0;
}