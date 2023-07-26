#include <iostream>
using namespace std;

int main(){
  int N, M; cin >> N >> M;

  int minP, minO; cin >> minP >> minO;
  int tmpP, tmpO;
  M--;
  while(M--){
    cin >> tmpP >> tmpO;
    if(tmpP < minP)
      minP = tmpP;
    if(tmpO < minO)
      minO = tmpO;
  }
  int result = minP < minO * 6 ? minP * (N / 6) : minO * (N / 6) * 6;
  result += minP < minO * (N % 6) ? minP : minO * (N % 6);
  cout << result;
}
