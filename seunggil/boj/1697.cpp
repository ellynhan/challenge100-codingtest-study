#include <iostream>
#include <queue>
#include <utility>
#include <set>
#include <vector>
using namespace std;

class mov {
public:
	int pos;
	int time = 0;
	bool plus = false;

	mov(int pos, int time, bool plus) : pos(pos), time(time), plus(plus) {}
};

int main(void) {
	int you, bro;
	cin >> you >> bro;

	if (bro <= you) {
		cout << you - bro;
		return 0;
	}

	vector<bool> canVisit(bro+2, true);
	queue<mov> bfs;
	if(you == 0)
		bfs.push(mov(1,1, false));
	else
		bfs.push(mov(you, 0, false));

	mov now(0,0,false);
	while (bfs.size()) {
		now = bfs.front();
		bfs.pop();
		canVisit[now.pos] = false;

		if (now.pos == bro) {
			cout << now.time;
			break;
		}

		if (now.pos + 1 <= bro && canVisit[now.pos + 1] && !now.plus)
			bfs.push(mov( now.pos + 1, now.time + 1, true));

		if (now.pos - 1 >= 0 && canVisit[now.pos - 1])
			bfs.push(mov(now.pos - 1, now.time + 1, false));

		if (now.pos * 2 <= bro + 1 && canVisit[now.pos * 2])
			bfs.push(mov(now.pos * 2, now.time + 1, false));
	}

	return 0;
}