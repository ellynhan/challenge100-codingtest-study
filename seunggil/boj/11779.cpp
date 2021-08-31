#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <list>

using namespace std;

int main(void) {
	int city, bus;
	cin >> city >> bus;
	vector<vector<int>> inputData(city+1, vector<int>(city+1, 200000000));

	while (bus--) {
		int i, j, cost;
		cin >> i >> j >> cost;
		if (cost < inputData[i][j])
			inputData[i][j] = cost;
	}

	for (int i = 1; i < city + 1; i++)
		inputData[i][i] = 0;

	int start, end;
	cin >> start >> end;
	
	vector<pair<int, int>> graph(city+1); // distance, prev
	set<pair<int, int>> dis;
	for (int i = 1; i < city + 1; i++) {
		graph[i] = { inputData[start][i], start };

		if (i != start)
			dis.insert({ inputData[start][i], i });
	}


	while (dis.size()) {
		pair<int,int> iter = *dis.begin();
		dis.erase(dis.begin());

		int cost = iter.first;
		int to = iter.second;

		for (int i = 1; i < city + 1; i++) {
			if (graph[i].first > (cost + inputData[to][i])) {
				dis.erase({ graph[i].first, i});
				graph[i].first = cost + inputData[to][i];
				graph[i].second = to;
				dis.insert({ graph[i].first,i});
			}
		}
	}


	cout << graph[end].first << '\n';
	list<int> route;
	route.push_back(end);
	int n = end;
	while (n != start) {
		route.push_back(graph[n].second);
		n = graph[n].second;
	}
	route.reverse();

	cout << route.size() << '\n';
	for (int iter : route)
		cout << iter << " ";

 	return 0;
}