#include <iostream>
#include <string>
#include <stack>

using namespace std;

#define MAX 1000
#define VISITED -1

int M, N;
string strMap = "";
int islandMap[MAX][MAX] = {0};

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // INPUT
  cin >> M >> N;

  string inp = "";
  cin >> inp;
  while(inp != "-1") {
    strMap += inp;
    cin >> inp;
  }

  int cursor = 0;
  for (int m = 0; m < M; m++) {
    for (int n = 0; n < N; n++) {
      islandMap[m][n] = strMap[cursor++] - '0';
    }
  }

  int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // direction
  // 좌 우 상 하

  // SOLVE
  stack<pair<int, int>> coor; // 갈 수 있는 좌표 넣는 자료구조 (coordinates)
  coor.push({0, 0});
  while(!coor.empty()) {
    int x = coor.top().first;
    int y = coor.top().second;
    coor.pop();

    if (islandMap[x][y] == VISITED) continue;

    for (int d = 0; d < 4; d++) {
      int next_x = x + dir[d][0];
      int next_y = y + dir[d][1];
      if (0 <= next_x && next_x < M &&
          0 <= next_y && next_y < N &&
          islandMap[next_x][next_y] == 0) {
            coor.push({next_x, next_y});
      }
    }
    islandMap[x][y] = VISITED;
  }

  int answer = 0;
  for (int m = 0; m < M; m++) {
    for (int n = 0; n < N; n++) {
      if (islandMap[m][n] == 0 || islandMap[m][n] == 1) answer++;
    }
  }

  // PRINT
  cout << answer << '\n';
}