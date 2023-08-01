#include <iostream>
#include <vector>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M; cin >> N >> M;
  vector<vector<int>> db;

  int i, j, temp, sum = 0;
  for (i = 0; i < N + 1; i++){
    vector<int> tmp;
    sum = 0;
    for (j = 0; j < N + 1; j++){
      if (i == 0 || j == 0){
        tmp.push_back(0);
      }
      else{
        cin >> temp;
        sum += temp;
        tmp.push_back(sum + db[i - 1][j]);
      }
    }
    db.push_back(tmp);
  }

  int x1, y1, x2, y2, result;
  while (M--){
    cin >> x1 >> y1 >> x2 >> y2;
    result = db[x2][y2] - db[x1 - 1][y2] - db[x2][y1 - 1] + db[x1 - 1][y1 - 1];
    cout << result << "\n";
  }
}
