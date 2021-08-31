#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int brother, me;

class placeInfo {
public:
	int mintime = -1; // 최단 도달시간
	int count = 0;
};
class moveInfo {
public:
	int mylocation;
	int time;

	moveInfo(int mylocation, int time) : mylocation(mylocation), time(time) {};
};

bool isValidPos(unordered_map<int, placeInfo>& map, moveInfo pos) {
	if (pos.mylocation < 0 || pos.mylocation > 100001)
		return false;
	if (pos.mylocation > brother + 1)
		return false;

	if (map[pos.mylocation].mintime != -1 && map[pos.mylocation].mintime < pos.time)
		return false;

	return true;
}
int main(void) {
	unordered_map<int, placeInfo> inputData;
	inputData.reserve(100000);
	
	cin >> me >> brother;

	if (brother <= me) {
		cout << me - brother << '\n';
		cout << 1;
		return 0;
	}

	queue<moveInfo> dfs;

	dfs.push(moveInfo(me, 0));
	while (dfs.size()) {
		moveInfo now = dfs.front();
		dfs.pop();
		if (now.mylocation == brother) {
			if (inputData[brother].mintime == -1 || inputData[brother].mintime > now.time) {
				inputData[brother].mintime = now.time;
				inputData[brother].count = 1;
			}
			continue;
		}
		if (inputData[brother].mintime != -1 && now.time > inputData[brother].mintime)
			continue;

		// 찾기 계속
		moveInfo next = moveInfo(now.mylocation +1, now.time + 1);

		if (isValidPos(inputData, next)) {
			if ((inputData[next.mylocation].mintime == -1) || (inputData[next.mylocation].mintime > next.time)) {
				inputData[next.mylocation].mintime = next.time;
				inputData[next.mylocation].count = 1;
				dfs.push(next);
				
			}
			else if (inputData[next.mylocation].mintime == next.time) {
				inputData[next.mylocation].count++;
				dfs.push(next);
			}
			
		}

		next = moveInfo(now.mylocation - 1, now.time + 1);

		if (isValidPos(inputData, next)) {
			if ((inputData[next.mylocation].mintime == -1) || (inputData[next.mylocation].mintime > next.time)) {
				inputData[next.mylocation].mintime = next.time;
				inputData[next.mylocation].count = 1;
				dfs.push(next);

			}
			else if (inputData[next.mylocation].mintime == next.time) {
				inputData[next.mylocation].count++;
				dfs.push(next);
			}

		}

		next = moveInfo(now.mylocation * 2, now.time + 1);
		if (isValidPos(inputData, next)) {
			if ((inputData[next.mylocation].mintime == -1) || (inputData[next.mylocation].mintime > next.time)) {
				inputData[next.mylocation].mintime = next.time;
				inputData[next.mylocation].count = 1;
				dfs.push(next);

			}
			else if (inputData[next.mylocation].mintime == next.time) {
				inputData[next.mylocation].count++;
				dfs.push(next);
			}
		}
	}

	cout << inputData[brother].mintime << '\n' << inputData[brother].count;
	return 0;
}