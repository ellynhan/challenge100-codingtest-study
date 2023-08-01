#include <iostream>
#include <vector>
using namespace std;

struct point{
  int x;
  int y;
  point(int xx, int yy):
    x{xx}, y{yy}{};
};

vector<point> db;

int getArea(){
  int area = 0;
  int i;
  for(i=0; i<db.size(); i++){
    if(i != db.size()-1)
      area += db[i].x * db[i+1].y;
    else
      area += db[i].x * db[0].y;
  }
  for(i=0; i<db.size(); i++){
    if(i != db.size()-1)
      area -= db[i].y * db[i+1].x;
    else
      area -= db[i].y * db[0].x;
  }
  area = abs(area) / 2;
  return area;
}

int main(){
  int N; cin >> N;
  int x = 0, y = 0;
  int dirct, leng;
  int i=6;
  while (i--){
    cin >> dirct >> leng;
    switch (dirct){
    case 1:{
      x += leng; break;
    }
    case 2:{
      x -= leng; break;
    }
    case 3:{
      y -= leng; break;
    }
    case 4:{
      y += leng; break;
    }
    default:
      break;
    }

    db.push_back(point(x, y));
  }

  cout << getArea() * N;
  return 0;
}
