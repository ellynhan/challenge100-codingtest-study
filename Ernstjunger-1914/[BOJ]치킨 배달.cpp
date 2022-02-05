#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

struct pos {
  int x, y;
};

int n, m;
int _min=987654321;
bool flag[13];
vector<pos> home;
vector<pos> choose;
vector<pos> chicken;

void func(int x, int cnt) {
  if(cnt==m) {
    int result=0;

    for(int i=0; i<home.size(); i++) {
      int mind=987654321;

      for(int j=0; j<choose.size(); j++) {
        mind=min(mind, abs(home[i].x-choose[j].x)+abs(home[i].y-choose[j].y));
      }
      result+=mind;
    }
    _min=min(_min, result);

    return;
  }

  for(int i=x; i<chicken.size(); i++) {
    if(flag[i]) {
      continue;
    } 

    flag[i]=1;
    choose.push_back({ chicken[i].x, chicken[i].y });
    func(i, cnt+1);
    flag[i]=0;
    choose.pop_back();
  }
}

int main() {
  ioboost;

  cin>>n>>m;

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      int tmp;
      cin>>tmp;

      if(tmp==1) {
        home.push_back({ i, j });
      } else if(tmp==2) {
        chicken.push_back({ i, j });
      }
    }
  }
  func(0, 0);
  cout<<_min<<"\n";

  return 0;
}