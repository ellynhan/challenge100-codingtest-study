#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)

void shiftRow(list<list<int>> &myRC)
{
  myRC.push_front(myRC.back());
  myRC.pop_back();
}

void rotate(list<list<int>> &myRC)
{
  int tmp2;

  auto it = myRC.begin();
  auto tmp_it = myRC.begin();
  it++;
  for (; it != myRC.end(); it++) {
    tmp_it->push_front(it->front());
    tmp_it++;
    it->pop_front();
  }

  int tmp4;

  auto it2 = myRC.rbegin();
  auto tmp_it2 = myRC.rbegin();
  it2++;
  for (; it2 != myRC.rend(); it2++) {
    tmp_it2->push_back(it2->back());
    tmp_it2++;
    it2->pop_back();
  }
}

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    vector<vector<int>> answer;
    list<list<int>> myRC;
    FOR(i, rc.size()) {
      list<int> tmp;
      FOR(j, rc[i].size()) {
        tmp.push_back(rc[i][j]);
      }
      myRC.push_back(tmp);
    }

    for (auto operation : operations) {
      if (operation[0] == 'S') {
        shiftRow(myRC);
      } else {
        rotate(myRC);
      }
    }
    
    for (auto it = myRC.begin(); it != myRC.end(); it++) {
      vector<int> tmp;
      for (auto it2 = it->begin(); it2 != it->end(); it2++) {
        tmp.push_back(*it2);
      }
      answer.push_back(tmp);
    }
    return answer;
}