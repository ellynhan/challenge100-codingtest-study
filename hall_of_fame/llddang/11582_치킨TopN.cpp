#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N; cin >> N;
  int tmpI, i, j;

  vector<int> sortV;
  vector<int> semiSort;
  
  for(i=0; i<N; i++){
    cin >> tmpI;
    sortV.push_back(tmpI);
  }
  int k; cin >> k;
  
  for(i=0; i<k; i++){
    for(j=0; j < N/k; j++){
      semiSort.push_back(sortV[(N/k)*i + j]);
    }
    sort(semiSort.begin() + (N/k)*i, semiSort.end());
  }
  for(auto tmp:semiSort){
    cout << tmp << " ";
  }
}
