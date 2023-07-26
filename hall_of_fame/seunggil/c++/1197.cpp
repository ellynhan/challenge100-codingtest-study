#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

class Edge {
public:
	int from;
	int to;
	int value;

	Edge(int from, int to, int value) :from(from), to(to), value(value) {}
};

vector<int> parent;
vector<Edge> inputData;

int find(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = find(parent[x]);
}

void setUnion(int x, int y) { // 2  4
	int parentX = find(x);			// 1
	int parentY = find(y);			// 3

	if (parentX > parentY) {		//1 > 3
		parent[parentX] = parentY;
	}
	else if (parentX < parentY) {	// 1 < 3
		parent[parentY] = parentX;	// parent[3] = 1
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int node, edge;
	cin >> node >> edge;

	parent = vector<int>(node + 1);

	for (size_t i = 1; i <= node; i++){
		parent[i] = i;
	}

	inputData.reserve(edge);

	for (int i = 0; i < edge; i++)
	{
		int from, to, value;
		cin >> from >> to >> value;
		inputData.emplace_back(from, to, value);
	}

	sort(inputData.begin(), inputData.end(), [](const Edge& s1, const Edge& s2) {
		return s1.value < s2.value;
	});

	int ans = 0;
	for(const Edge& e : inputData){
		int parentX = find(e.from);
		int parentY = find(e.to);

		if (parentX == parentY) {
			continue;
		}
		else {
			ans += e.value;
			setUnion(e.from, e.to);
		}
	}

	cout << ans;

	return 0;
}