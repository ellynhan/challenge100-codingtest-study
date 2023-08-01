#include <vector>
#include <queue>
#include <cstdio>
#include <unordered_set>
#include <functional>
using namespace std;

vector<vector<int>> inputData;
int n;


class pos {
public:
	int x;
	int y;
	int time;

	pos(int x = 0, int y = 0, int time = -1) : x(x), y(y), time(time) {}
	static bool isValid(const pos& other) {
		if (other.x < 0 || other.x >= n)
			return false;
		if (other.y < 0 || other.y >= n)
			return false;

		return true;
	}

	// unordered set
	bool operator == (const pos& p2) const {
		if (x != p2.x)
			return false;
		return y == p2.y;
	}

	// priority queue
	bool operator > (const pos& p2) const {
		if (time != p2.time)
			return time > p2.time;
		if (x != p2.x)
			return x > p2.x;
		return y > p2.y;
	}
};
struct posHash {
	size_t operator() (const pos& p) const {
		return (hash<int>{}(p.x) ^ hash<int>{}(p.y));
	}
};
class shark {
public:
	int level = 2;
	int exp = 0;

	void eat() {
		exp++;
		if (level == exp) {
			level++;
			exp = 0;
		}
	}

};


int main(void) {
	
	scanf("%d", &n);

	inputData = vector<vector<int>>(n, vector<int>(n));
	shark baby;
	pos startlocation;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &inputData[i][j]);
			if (inputData[i][j] == 9) {
				inputData[i][j] = 0;
				startlocation.x = i;
				startlocation.y = j;
			}
		}
	
	queue<pos> bfs;
	priority_queue<pos, vector<pos>, greater<pos>> selection;
	int length = ~(1 << 31);
	int answer = 0;
	unordered_set<pos,posHash> visited;

	bfs.push(startlocation);

	while (true) {
		pos newPos;
		while (bfs.size()) {
			newPos = bfs.front();
			bfs.pop();
			if (!pos::isValid(newPos))
				continue;
			if (visited.count(newPos))
				continue;
			if (newPos.time > length)
				continue;

			visited.insert(newPos);
			newPos.time++;

			if (baby.level < inputData[newPos.x][newPos.y])
				continue;
			else if (inputData[newPos.x][newPos.y] > 0 && baby.level > inputData[newPos.x][newPos.y]) {
				length = newPos.time;
				selection.push(newPos);
				continue;
				
			}

			bfs.push(pos(newPos.x - 1, newPos.y, newPos.time));
			bfs.push(pos(newPos.x, newPos.y - 1, newPos.time));
			bfs.push(pos(newPos.x, newPos.y + 1, newPos.time));
			bfs.push(pos(newPos.x + 1, newPos.y, newPos.time));
		}

		if (selection.empty())
			break;

		newPos = selection.top();
		selection.pop();

		baby.eat();
		inputData[newPos.x][newPos.y] = 0;
		answer += newPos.time;
		newPos.time = -1;
		
		selection = priority_queue<pos, vector<pos>, greater<pos>>();
		visited.clear();
		length = ~(1 << 31);
		bfs.push(pos(newPos.x, newPos.y, newPos.time));
	}

	printf("%d\n", answer);
	return 0;
}