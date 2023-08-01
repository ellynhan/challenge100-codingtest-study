#include <iostream>
using namespace std;

int main(){
  int stand;cin >> stand;
  int N; cin >> N;
  int x, y;
  int sum =0;
  while(N--){
    cin >> x >> y;
    sum += x*y;
  }
  string answer = sum==stand ? "Yes" : "No";
  cout << answer;
}
