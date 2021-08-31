#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	int maxValue[3];
	int minValue[3];

	int newMaxValue[3];
	int newMinValue[3];

	int a, b, c;
	cin >> a >> b >> c;

	maxValue[0] = a;
	maxValue[1] = b;
	maxValue[2] = c;

	minValue[0] = a;
	minValue[1] = b;
	minValue[2] = c;


	for (int i = 1; i < N; i++) {
		cin >> newMaxValue[0] >> newMaxValue[1] >> newMaxValue[2];

		for (int i = 0; i < 3; i++)
			newMinValue[i] = newMaxValue[i];
		

		newMaxValue[0] += maxValue[0] < maxValue[1] ? maxValue[1] : maxValue[0];
		newMaxValue[2] += maxValue[1] < maxValue[2] ? maxValue[2] : maxValue[1];

		if (maxValue[0] < maxValue[1]) {
			if (maxValue[1] < maxValue[2])
				newMaxValue[1] += maxValue[2];
			else
				newMaxValue[1] += maxValue[1];
		}
		else {
			if(maxValue[0] < maxValue[2])
				newMaxValue[1] += maxValue[2];
			else
				newMaxValue[1] += maxValue[0];
		}

		newMinValue[0] += minValue[0] > minValue[1] ? minValue[1] : minValue[0];
		newMinValue[2] += minValue[1] > minValue[2] ? minValue[2] : minValue[1];

		if (minValue[0] < minValue[1]) {
			if (minValue[0] < minValue[2])
				newMinValue[1] += minValue[0];
			else
				newMinValue[1] += minValue[2];
		}
		else {
			if (minValue[1] < minValue[2])
				newMinValue[1] += minValue[1];
			else
				newMinValue[1] += minValue[2];
		}

		for (int i = 0; i < 3; i++) {
			minValue[i] = newMinValue[i];
			maxValue[i] = newMaxValue[i];
		}
	}

	int answer1 = maxValue[0];
	int answer2 = minValue[0];
	for (int i = 1; i < 3; i++) {
		if (answer1 < maxValue[i])
			answer1 = maxValue[i];
		if (answer2 > minValue[i])
			answer2 = minValue[i];
	}
	cout << answer1 << " " << answer2;

	return 0;
}