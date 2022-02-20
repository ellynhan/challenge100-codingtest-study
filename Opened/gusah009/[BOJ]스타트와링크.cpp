#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define MAX 20
#define INF 1987654321

int N;
int S[MAX][MAX] = {0};
bool team[MAX] = {0};
int answer = INF;

void input()
{
  cin >> N;
  FOR(i, N) {
    FOR(j, N) {
      cin >> S[i][j];
    } 
  }

  FOR(n, N / 2) team[n] = true;
  sort(team, team + N);
}

void solve()
{
  int team1Score, team2Score;
  int diff = 0;
	do {
    vector<int> team1, team2;
    FOR(n, N) {
      if (team[n]) {
        team1.push_back(n);
      } else {
        team2.push_back(n);
      }
		}
    team1Score = 0;
    team2Score = 0;
    FOR(i, N / 2) {
      for (int j = i + 1; j < N / 2; j++) {
        team1Score += S[team1[i]][team1[j]];
        team1Score += S[team1[j]][team1[i]];
        team2Score += S[team2[i]][team2[j]];
        team2Score += S[team2[j]][team2[i]];
      }
    }
    answer = min(answer, abs(team1Score - team2Score));
	} while(next_permutation(team, team + N));
}

void print()
{
  cout << answer << '\n';
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