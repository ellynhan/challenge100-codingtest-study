#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll=long long;

int n;
int _min=1000000001, _max=-1000000001;
int opers[4], seq[11];

void func(int result, int index) {
  if(index==n) {
    if(result>_max) {
      _max=result;
    }
    if(result<_min) {
      _min=result;
    }
    return;
  }

  for(int i=0; i<4; i++) {
    if(opers[i]>0) {
      opers[i]--;

      if(i==0) {
        func(result+seq[index], index+1);
      } else if(i==1) {
        func(result-seq[index], index+1);
      } else if(i==2) {
        func(result*seq[index], index+1);
      } else if(i==3) {
        func(result/seq[index], index+1);
      }
      opers[i]++;
    }
  }
  return;  
}

int main() {
  ioboost;

  cin>>n;

  for(int i=0; i<n; i++) {
    cin>>seq[i];
  }

  for(int i=0; i<4; i++) {
    cin>>opers[i];
  }

  func(seq[0], 1);
  cout<<_max<<"\n"<<_min<<"\n";
  
  return 0;
}