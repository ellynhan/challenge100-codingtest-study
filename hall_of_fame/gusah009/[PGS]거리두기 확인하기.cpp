#include <string>
#include <vector>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define MAX_DIST 2
#define MAX_I 5
#define MAX_J 5

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool isVisited[MAX_I][MAX_J] = {0};

bool func(int i, int j, int depth, vector<string>& place)
{
  if (depth > 0 && place[i][j] == 'P') return false;

  if (depth == MAX_DIST) {
    return true;
  }

  int next_i, next_j;
  FOR(d, 4) {
    next_i = i + dir[d][0];
    next_j = j + dir[d][1];
    if ((0 <= next_i && next_i < place.size()) &&
        (0 <= next_j && next_j < place[i].size()) &&
        (!isVisited[next_i][next_j]) &&
        (place[i][j] == 'O' || place[i][j] == 'P')) {
      isVisited[next_i][next_j] = true;
      if (!func(next_i, next_j, depth + 1, place)) {
        return false;
      }
      isVisited[next_i][next_j] = false;
    }
  }
  return true;
}

bool solve(vector<string>& place)
{
  FOR(i, place.size()) {
    FOR(j, place[i].size()) {
      if (place[i][j] == 'P') {
        isVisited[i][j] = true;
        if (!func(i, j, 0, place)) {
          return false;
        }
        isVisited[i][j] = false;
      }
    }
  }
  return true;
}

void init() {
    FOR(i, MAX_I) {
      FOR(j, MAX_J) {
        isVisited[i][j] = 0;
      }
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    int T = places.size();
    FOR(t, T) {
      init();
      vector<string> place = places[t];
      answer.push_back(solve(place));
    }
    return answer;
}