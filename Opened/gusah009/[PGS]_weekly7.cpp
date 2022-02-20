#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

bool people[1001][1001] = {0};

set<int> S;

vector<int> solution(vector<int> enter, vector<int> leave) {
    vector<int> answer;
    FOR (l, leave.size()) {
        int maximum_show = -1;
        int start = find(enter.begin(), enter.end(), leave[l]) - enter.begin();
        for (auto it = S.begin(); it != S.end(); it++) {
          maximum_show = max(maximum_show, int(find(enter.begin(), enter.end(), *it) - enter.begin()));
        }
        for (int i = start + 1; i <= maximum_show; i++) {
          people[leave[l]][enter[i]] = true;
          people[enter[i]][leave[l]] = true;
        }
        S.insert(leave[l]);
    }

    for (int i = 1; i <= enter.size(); i++) {
      int sum = 0;
      for (int j = 1; j <= enter.size(); j++) {
        sum += people[i][j];
      }
      answer.push_back(sum);
    }
    return answer;
}