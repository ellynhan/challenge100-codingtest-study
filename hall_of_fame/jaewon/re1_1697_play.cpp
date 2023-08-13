//0250 ~ 0251
//0257 ~ 0313
#include <iostream>
#include <queue>
using namespace std;

int N, K;
int arr[100'001] = { 0 };

int main() {
	cin >> N >> K;
	if (N >= K) {
		cout << N - K;
	}
	else {
		arr[N] = 1;
		queue<pair<int, int>> q;
		q.push({ N, 1});
		int standard = 100'001;
		while (!q.empty()) {
			int curr = q.front().first;
			int time = q.front().second;
			q.pop();

			if (curr == K) {
				standard = time;
			}
			time += 1;

			int dx[3] = { curr - 1, curr + 1, curr * 2 };
			for (int i = 0; i < 3; i++) {
				if (dx[i] < 0 || dx[i] > 100'000)continue;
				if (arr[dx[i]] == 0 || arr[dx[i]] > time) {
					arr[dx[i]] = time;
					if (time < standard) {
						q.push({ dx[i], time });
					}
				}
			}
		}
		cout << arr[K]-1;
	}
}
//N에서 K로 이동할 수 있는 최소 시간
// X에서 X-1 / X+1 / X*2 로 이동이 가능하고 각각 1초가 소요된다.
//-1 때문에 계산하기가 영 이상하다 
