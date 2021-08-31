#include <vector>
#include <iostream>

constexpr auto INF = 1600000;

using namespace std;

int main(void) {
	int edge, vertex;
	
	cin >> edge >> vertex;

	vector<vector<int>> inputData(edge, vector<int>(edge, INF));

	for (int i = 0; i < edge; i++)
		inputData[i][i] = 0;
	

	while (vertex--) {
		int a, b, value;
		cin >> a >> b >> value;
		a--; b--;

		inputData[a][b] = value;
		inputData[b][a] = value;
	}

	for (int waypoint = 0; waypoint < edge; waypoint++)
		for (int start = 0; start < edge; start++)
			for (int end = start + 1; end < edge; end++) {
				int newLength = inputData[start][waypoint] + inputData[waypoint][end];
				if (inputData[start][end] > newLength) {
					inputData[start][end] = newLength;
					inputData[end][start] = newLength;
				}
			}

	int waypoint1, waypoint2;
	cin >> waypoint1 >> waypoint2;
	waypoint1--; waypoint2--;
	int answer1 = inputData[0][waypoint1] + inputData[waypoint1][waypoint2] + inputData[waypoint2][edge - 1];
	int answer2 = inputData[0][waypoint2] + inputData[waypoint2][waypoint1] + inputData[waypoint1][edge - 1];

	if (answer1 >= INF && answer2 >= INF)
		cout << -1 << '\n';
	else
		cout << (answer1 > answer2 ? answer2 : answer1) << '\n';

	//for (int i = 0; i < edge; i++) {
	//	for (int j = 0; j < edge; j++) {
	//		cout << inputData[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	return 0;
}