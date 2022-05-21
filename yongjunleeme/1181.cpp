#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector <string> v;

bool cmp(const string &a, const string &b){
  int a_size = a.size();
  int b_size = b.size();
  if(a_size != b_size) return a_size < b_size;
  return a < b;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> s;
    v.push_back(s);
  }
  sort(v.begin(), v.end(), cmp);
  v.erase(unique(v.begin(), v.end()), v.end());
  for(auto i: v) cout << i << '\n';
}
