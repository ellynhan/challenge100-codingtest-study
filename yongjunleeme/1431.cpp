#include <bits/stdc++.h>
using namespace std;

int n;
vector <string> s;

bool cmp(string& a, string& b){
  int a_size = a.size();
  int b_size = b.size();
  int aa = 0, bb = 0;
  if(a_size != b_size) return a_size < b_size;
  for(int i = 0; i < a_size; i++)
    if(isdigit(a[i])) aa += (a[i] - '0');
  for(int i = 0; i < b_size; i++)
    if(isdigit(b[i])) bb += (b[i] - '0');
  if(aa != bb) return aa < bb;
  return a < b;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    string a;
    cin >> a;
    s.push_back(a);
  }
  sort(s.begin(), s.end(), cmp);
  for(int i = 0; i < n; i++) cout << s[i] << '\n';
}
