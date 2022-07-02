#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)
#define MAX_ALP 150 + 30 + 1
#define MAX_COP 150 + 30 + 1
#define INF 987654321

int DP[MAX_ALP][MAX_COP];

void init(int alp, int cop)
{
  FOR(i, MAX_ALP) {
    FOR(j, MAX_COP) {
      DP[i][j] = INF;
    }
  }
  FOR(i, alp + 1) {
    FOR(j, cop + 1) {
      DP[i][j] = 0;
    }
  }
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int goalAlp = 0, goalCop = 0;
    for (auto problem: problems) {
      goalAlp = max(goalAlp, problem[0]);
      goalCop = max(goalCop, problem[1]);
    }

    init(alp, cop);

    int alpTraining, copTraining, alpTmp, copTmp;
    for (int i = alp; i < MAX_ALP; i++) {
      for (int j = cop; j < MAX_COP; j++) {
        alpTraining = i == 0 ? INF : DP[i - 1][j] + 1;
        copTraining = j == 0 ? INF : DP[i][j - 1] + 1;
        DP[i][j] = min(min(DP[i][j], alpTraining), copTraining);
        for (auto problem: problems) {
          alpTmp = i - problem[2] >= alp ? i - problem[2] : alp;
          copTmp = j - problem[3] >= cop ? j - problem[3] : cop;
          if ((alpTmp >= problem[0]) && (copTmp >= problem[1])) {
            DP[i][j] = min(DP[i][j], DP[alpTmp][copTmp] + problem[4]);
          }
        }
      }
    }

    answer = DP[goalAlp][goalCop];
    for (int i = goalAlp; i < MAX_ALP; i++) {
      for (int j = goalCop; j < MAX_COP; j++) {
        answer = min(answer, DP[i][j]);
      }
    }

    return answer;
}