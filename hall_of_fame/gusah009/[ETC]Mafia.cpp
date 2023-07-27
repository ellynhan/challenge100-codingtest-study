#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define SIZE 1000

// 1. 부하직원의 수
// 2. tree의 depth
// 3. 자기 자신 아래에 최대 depth
// 4. 이름
pair<pair<int, int>, pair<int, string> > mafias[SIZE];
vector<int> pointPersonTree[SIZE], pointBossTree[SIZE];
map<string, int> nameToNum;
map<int, string> numToName;
int N;

void input()
{
  cin >> N;
  string person, boss;
  int personNum, bossNum;
  int nodeNum = 0;
  for (int n = 0; n < N - 1; n++) {
    cin >> person >> boss;
    if (nameToNum.find(person) != nameToNum.end()) { // name is Exist!
      personNum = nameToNum[person];
    } else {
      personNum = nodeNum;
      nameToNum.insert({person, personNum});
      numToName.insert({personNum, person});
      nodeNum++;
    }
    if (nameToNum.find(boss) != nameToNum.end()) { // name is Exist!
      bossNum = nameToNum[boss];
    } else {
      bossNum = nodeNum;
      nameToNum.insert({boss, bossNum});
      numToName.insert({bossNum, boss});
      nodeNum++;
    }

    pointPersonTree[bossNum].push_back(personNum);
    pointBossTree[personNum].push_back(bossNum);
  }
}

int DFS1(int bossNode)
{
  int personCount = 1;
  if (pointPersonTree[bossNode].empty()) {
    mafias[bossNode].first.first = 0;
    return personCount;
  }

  for (auto it = pointPersonTree[bossNode].begin(); it != pointPersonTree[bossNode].end(); it++) {
    personCount += DFS1(*it);
  }

  mafias[bossNode].first.first = -(personCount - 1);
  return personCount;
}

void DFS2(int bossNode, int depth)
{
  mafias[bossNode].first.second = depth;
  for (auto it = pointPersonTree[bossNode].begin(); it != pointPersonTree[bossNode].end(); it++) {
    DFS2(*it, depth + 1);
  }
}

int DFS3(int bossNode)
{
  int personDepth = 0;
  if (pointPersonTree[bossNode].empty()) {
    mafias[bossNode].second.first = -personDepth;
    return personDepth;
  }

  for (auto it = pointPersonTree[bossNode].begin(); it != pointPersonTree[bossNode].end(); it++) {
    personDepth = max(personDepth, DFS3(*it) + 1);
  }

  mafias[bossNode].second.first = -personDepth;
  return personDepth;
}

void solve()
{
  int primaryBossNum = -1;
  for (int n = 0; n < N; n++) {
    if (pointBossTree[n].size() == 0) {
      primaryBossNum = n;
      break;
    }
  }

  // 1
  DFS1(primaryBossNum);

  // 2
  DFS2(primaryBossNum, 0);
  // 3
  DFS3(primaryBossNum);

  // 4
  for (int n = 0; n < N; n++) {
    // cout << numToName[n] << '\n';
    mafias[n].second.second = numToName[n];
  }

  sort(mafias, mafias + N);
}

void print()
{   
  for (int n = 0; n < N; n++) {
    cout << mafias[n].second.second << '\n';
  }
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  print();
}