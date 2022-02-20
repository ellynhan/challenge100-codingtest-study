#include <bits/stdc++.h>
using namespace std;

int l, c;
char s[20];

bool aeiou(char t){
  return t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u';
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> l >> c;
  for(int i = 0; i < c; i++) cin >> s[i];
  sort(s, s+c);
  vector<int> brute(c);
  for(int i = l; i < c; i++) brute[i] = 1;
  do{
    string ans;
    int cnt1 = 0;
    for(int i = 0; i < c; i++){
      if(brute[i] == 0){
        ans += s[i];
        if(aeiou(s[i])) cnt1++;
      }
    }
    if(cnt1 < 1 || l - cnt1 < 2) continue;
    cout << ans << "\n";
  }while(next_permutation(brute.begin(), brute.end()));
}


/*
#include <bits/stdc++.h>
using namespace std;

int l, c;
char arr[15];

bool aeiou(char t){
  return t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u';
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> l >> c;
  for(int i = 0; i < c; i++) cin >> arr[i];
  sort(arr, arr+c);
  vector<int> brute(c);
  for(int i = l; i < c; i++) brute[i] = 1;
  do{
    string ans;
    int cnt = 0;
    for(int i = 0; i < c; i++){
      if(!brute[i]){
        ans += arr[i];
        if(aeiou(arr[i])) cnt++;
      }
    }
    if(cnt < 1 || l-cnt < 2) continue; // l-cnt < 2--> 최소 두 개의 자음
    cout << ans << '\n';
  }while(next_permutation(brute.begin(), brute.end()));
}
*/
