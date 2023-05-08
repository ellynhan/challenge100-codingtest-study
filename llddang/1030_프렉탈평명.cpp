#include <iostream>
using namespace std;


int arr[50][50] = {0, };
int s, N, K;
int r1, r2;
int c1, c2;

void fractal(int currX, int currY, int currN){
  if(currN == 1) return;
  if(currX > c2 || currX + currN - 1 < c1) return;
  if(currY > r2 || currY + currN - 1 < r1) return;
  
  int nextN = currN / N;
  int offset = (currN - nextN * K) / 2;

  int minX = currX + offset, maxX = currX + currN - offset;
  int minY = currY + offset, maxY = currY + currN - offset;

  for(int y = minY < r1 ? r1 : minY; y < maxY && y <= r2; y++)
    for(int x = minX < c1 ? c1 : minX; x < maxX && x <= c2; x++)
      arr[y-r1][x-c1] = 1;
  
  for(int y = currY; y < currY + currN; y += nextN){
    for(int x = currX; x < currX + currN; x += nextN){
      if(minX <= x && x < maxX && minY <= y && y < maxY) continue;
      fractal(x, y, nextN);
    }
  }
}

int main(){
  cin >> s >> N >> K;
  cin >> r1 >> r2;
  cin >> c1 >> c2;

  int n = 1;
  for(int i=0; i<s; i++) n *= N;

  fractal(0, 0, n);

  for(int y=0; y<r2-r1+1; y++){
    for(int x=0; x<c2-c1+1; x++){
      cout << arr[y][x];
    }
    cout << "\n";
  }

}
