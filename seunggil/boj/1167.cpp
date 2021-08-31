#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <list>
#include <set>
using namespace std;


class line {
public:
	int to;
	int length;

	line(int a, int b) : to(a), length(b) {}
};

class vertex {
public:
	multiset<int, greater<int>> dp = multiset<int, greater<int>>({ 0 });
	list<line> childNodes;
};

int main(void) {
	int vertexCount;
	scanf("%d", &vertexCount);
	vector<bool> checked = vector<bool>(vertexCount + 1);
	vector<vertex> haveSmallChild = vector<vertex>(vertexCount + 1);
	queue<int> bfs;
	for (int i = 0; i < vertexCount; i++) {
		int vertexIndex;
		scanf("%d", &vertexIndex);

		int to, length;
		scanf("%d", &to);

		while (to != -1) {
			scanf("%d", &length);
			haveSmallChild[vertexIndex].childNodes.push_back(line(to, length));
			scanf("%d", &to);
		}

		if (haveSmallChild[vertexIndex].childNodes.size() == 1)
			bfs.push(vertexIndex);
	}

	
	while (bfs.size()) {
		int index = bfs.front();
		bfs.pop();

		if (checked[index])
			continue;

		vertex q = haveSmallChild[index];

		int count = 0;
		for (const line& iter : q.childNodes) {
			if (!checked[iter.to])
				count++;
			if (count >= 2)
				break;
		}
		if (count >= 2) {
			bfs.push(index);
			continue;
		}

		checked[index] = true;
		int maxValue = *q.dp.begin();
		for (const line child : q.childNodes) {
			if (!checked[child.to]) {
				haveSmallChild[child.to].dp.insert(maxValue + child.length);
				bfs.push(child.to);
			}
		}

	}

	int answer = 0;

	for (const vertex& iter : haveSmallChild) {
		int cand;

		if (iter.dp.size() < 2)
			continue;
			
		cand = *iter.dp.begin() + *(++iter.dp.begin());
		if (cand > answer)
			answer = cand;
	}

	printf("%d", answer);
	return 0;
}