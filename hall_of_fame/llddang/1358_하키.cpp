#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct point{
  point(int xx, int yy, int c=0):
    x{xx}, y{yy}, check{c}{};
  int x;
  int y;
  int check;
};

int W, H, X, Y;

bool checkCircle(int circleX, int circleY, int x, int y){
  int height = H/2;
  return (pow(height, 2) >= pow(circleX-x, 2) + pow(circleY-y, 2));
}

int main(){
  int P;
  cin >> W >> H >> X >> Y >> P;
  
  vector<point> players;
  int x, y, i;
  
  while(P--){
    cin >> x >> y;
    players.push_back(point(x, y));
  }

  int result = 0;
  for(i=0; i<players.size(); i++){
    x = players[i].x;
    y = players[i].y;
    if(X <= x && x <= X+W && Y <= y && y <= Y+H)
      result += 1;
    else if(checkCircle(X, Y + H/2, x, y))
      result += 1;
    else if(checkCircle(X+W, Y+H/2, x, y))
      result += 1;
  }
  cout << result;
}
