#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int houseCount;
int chickenCount;

bool combination[14] = {true, true, true, true, true, true, true, true, true, true, true, true, true, true};
int map[27][101] = {};

int ans = (1 << 31) - 1;


void dfs(int index, int now, int want) {
	
	if (now == want) { // 폐업 지역 결정.
		int a = 0;
		for (int i = 1; i <= houseCount; i++) { // 집 마다 치킨 거리 계산
			int length = (1 << 31) - 1;
			for (int j = 1; j <= chickenCount; j++) { // 치킨집
				if (combination[j] == false) // 폐업이면 ㄴ
					continue;
				length = length < map[j][i] ? length : map[j][i];
			}
			a += length;
		}
		ans = ans < a ? ans : a;
		return;
	}
	if (index > chickenCount)
		return;

	for (int i = index; i <= chickenCount; i++) {
		combination[i] = false;
		dfs(i + 1, now + 1, want);
		combination[i] = true;
	}

}

class pos {
public:
	int x;
	int y;
	pos(int x, int y):x(x),y(y){}

	int getLength(pos other) {
		return abs(x - other.x) + abs(y - other.y);
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int closingChicken;

	cin >> n >> m;

	
	vector<pos> house;
	vector<pos> chicken;

	house.reserve(n * 2);
	chicken.reserve(m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int type;
			cin >> type;
			if (type == 1) {
				house.emplace_back(i, j);
			}
			else if (type == 2) {
				chicken.emplace_back(i, j);
			}
		}
	}

	closingChicken = chicken.size() - m;

	houseCount = house.size();
	chickenCount = chicken.size();

	for (int i = 0; i < chicken.size(); i++)
		for (int j = 0; j < house.size(); j++)
			map[i+1][j+1] = chicken[i].getLength(house[j]);


	dfs(1, 0, closingChicken);

	cout << ans << '\n';

	return 0;
}