#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, M;
vector<int> graph[1001];
int visited[1001] = {0};
bool isUsed[1001] = {0};
void input()
{
  cin >> N >> M;
  FOR(m, M) {
    int singer;
    cin >> singer;
    
    int prev_singer_no;
    cin >> prev_singer_no;
    for(int i = 1; i < singer; i++) {
      int singer_no;
      cin >> singer_no;
      graph[singer_no].push_back(prev_singer_no);
      prev_singer_no = singer_no;
    }
  }
}

bool findCycleAlgorithm(int here) {
  if (visited[here]) {
    if (visited[here] == -1) {
      return true;
    }
    return false;
  }
   
  visited[here] = -1;
  for (int there : graph[here]) {
    if (findCycleAlgorithm(there)) {
      return true;
    }
  }
  visited[here] = 1;
   
  return false;
}


// √‚√≥: https://kesakiyo.tistory.com/15 [Problem Solving]

void solve()
{
  bool flag = false;
  FOR(n, N + 1) {
    if (findCycleAlgorithm(n)) {
      flag = true;
      break;
    }
  }
  if (flag) {
    cout << 0 << '\n';
    return;
  } else {
    queue<int> Q;
    for(int n = 1; n <= N; n++) {
      if (graph[n].size() == 0) {
        isUsed[n] = true;
        Q.push(n);
      }
    }
    while(!Q.empty()) {
      int next = Q.front();
      cout << next << '\n';
      Q.pop();
      FOR(n, N + 1) {
        graph[n].erase(std::remove(graph[n].begin(), graph[n].end(), next), graph[n].end());
      }
      for(int n = 1; n <= N; n++) {
        if (!isUsed[n]) {
          if (graph[n].size() == 0) {
            isUsed[n] = true;
            Q.push(n);
          }
        }
      }
    }
  }
}

void print()
{

}

int main()
{
  // ios_base :: sync_with_stdio(false);
  // cin.tie(NULL);
  // cout.tie(NULL);
  input();
  solve();
  print();
}