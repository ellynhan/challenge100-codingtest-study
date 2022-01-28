#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
vector<int> num(10);
vector<vector<int>> ans;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> num[i];

  sort(num.begin(), num.begin()+n);
  fill(arr+m, arr+n, 1);

  do{
    vector<int> tmp;
    for(int i = 0; i < n; i++)
      if(!arr[i]) tmp.push_back(num[i]);

    do{
      ans.push_back(tmp);
    }while(next_permutation(tmp.begin(), tmp.end()));
  }while(next_permutation(arr, arr+n));

  sort(ans.begin(), ans.end());
  for(auto a: ans){
    for(auto b: a) cout << b << " ";
    cout << "\n";
  }
}

/*
#include <bits/stdc++.h>
using namespace std;

int isused[10];
int arr[10];
int num[10];
int n, m;

void func(int k){
  if(k == m){
    for(int i = 0; i < m; i++) cout << num[arr[i]] << " ";
    cout << "\n";
    return;
  }
  for(int i = 0; i < n; i++){
    if(!isused[i]){
      arr[k] = i;
      isused[i] = 1;
      func(k+1);
      isused[i] = 0;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> num[i];
  sort(num, num+n);
  func(0);
}
*/