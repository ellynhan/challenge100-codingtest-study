#include <string> // 40m
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define MAX_N 50000 + 1
#define INF 1987654321

vector<pair<int, int> > myPath[MAX_N]; // w, next
bool isGate[MAX_N] = {0};
bool isSummit[MAX_N] = {0};
int dist[MAX_N];

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits)
{
  vector<int> answer;
  pair<int, int> myAnswer = {-1, INF};

  for (auto p : paths) {
    myPath[p[0]].push_back({p[2], p[1]});
    myPath[p[1]].push_back({p[2], p[0]});
  }

  for (auto g : gates) {
    isGate[g] = true;
  }

  for (auto s : summits) {
    isSummit[s] = true;
  }

  FOR(i, MAX_N) {
    dist[i] = INF;
  }

  for (auto summit : summits) {
    priority_queue<pair<int, int>> PQ;
    PQ.push(make_pair(0, summit));
    dist[summit] = 0;

    int cost, cur;
    while (PQ.empty() == 0)
    {
      cost = -PQ.top().first;
      cur = PQ.top().second;
      PQ.pop();

      for (int i = 0; i < myPath[cur].size(); i++)
      {
        int Next = myPath[cur][i].second;
        int nCost = max(cost, myPath[cur][i].first);
        if (isSummit[Next]) continue;
        if (isGate[Next]) {
          if (myAnswer.second > nCost) {
            myAnswer = {summit, nCost};
          } else if (myAnswer.second == nCost && myAnswer.first > summit) {
            myAnswer.first = summit;
          }
          continue;
        }
        if (dist[Next] > nCost)
        {
          dist[Next] = nCost;
          PQ.push(make_pair(-dist[Next], Next));
        }
      }
    }
  }

  answer.push_back(myAnswer.first);
  answer.push_back(myAnswer.second);
  return answer;
}