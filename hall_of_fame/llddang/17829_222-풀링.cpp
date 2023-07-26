#include <iostream>
#define MAX 1025
using namespace std;

int second(int a, int b, int c, int d){
  int max1 = max(a, b);
  int min1 = min(a, b);
  int max2 = max(c, d);
  int min2 = min(c, d);
  
  if(max1 > max2){
    return max(min1, max2);
  } else {
    return max(min2, max1);
  }
}

int main(){
  int N; cin >> N;
  int data[MAX][MAX];
  int i, j;
  for(i=0; i<N; i++){
    for(j=0; j<N; j++){
      cin >> data[i][j];
    }
  }
  int pointI, pointJ;
  while(N != 1){
    pointI=0;
    for(i=0; i<N; i+=2){
      pointJ=0;
      for(j=0; j<N; j+=2){
        data[pointI][pointJ]=second(data[i][j], data[i][j+1], data[i+1][j], data[i+1][j+1]);
        pointJ++;
      }
      pointI++;
    }
    N /= 2;
  }

  cout << data[0][0];
}
