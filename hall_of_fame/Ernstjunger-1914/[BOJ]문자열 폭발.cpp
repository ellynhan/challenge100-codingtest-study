#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main() {
  ioboost;

  string str, str_bomb, ans="";
  cin>>str>>str_bomb;

  int b_index=str_bomb.length()-1;

  for(int i=0; i<str.length(); i++) {
    ans+=str[i];

    if(ans[ans.length()-1]==str_bomb[b_index]) {
      if(ans.length()>=str_bomb.length()) {
        int cnt=1;

        for(int j=b_index-1; j>=0; j--) {
          if(ans[ans.length()-(b_index-j)-1]==str_bomb[j]) {
            cnt++;
          }
        }

        if(str_bomb.length()==cnt) {
          for(int j=0; j<str_bomb.length(); j++) {
            ans.pop_back();
          }
        }
      }
    }
  }

  if(ans.length()>0) {
    cout<<ans<<"\n";
  } else {
    cout<<"FRULA\n";
  }
  return 0;
}