#include <iostream>
#include <vector>
using namespace std;

struct point{
  int x;
  int y;
  point(int xx, int yy):
    x(xx), y(yy){};
};

int length(point a, point b){
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool check(point start, point end, point which, int r){
  int lenStart = length(start, which);
  int lenEnd = length(end, which);
  return (r * r < lenStart) && (r * r > lenEnd);
}

int main(){
  int T; cin >> T;
  int tmpx, tmpy, tmpr;
  vector<int> answers;
  while(T--){
    cin >> tmpx >> tmpy;
    point start = point(tmpx, tmpy);
    cin >> tmpx >> tmpy;
    point end = point(tmpx, tmpy);

    int n; cin >> n;
    int answer = 0;
    while(n--){
      cin >> tmpx >> tmpy >> tmpr;
      point tmp = point(tmpx, tmpy);
      if(check(start, end, tmp, tmpr)){ 
         answer++;
      }else if(check(end, start, tmp, tmpr)){
         answer++;
      }
    }
    answers.push_back(answer);
  }
  for(auto answer:answers){
    cout << answer << "\n";
  }
}
