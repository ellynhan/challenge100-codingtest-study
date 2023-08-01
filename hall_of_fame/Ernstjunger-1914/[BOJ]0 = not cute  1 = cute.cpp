#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main() {
  ioboost;

  int n;
  int result[2]={ 0 };
  cin>>n;

  for(int i=0; i<n; i++) {
    int tmp;
    cin>>tmp;
    result[tmp]+=1;
  }
  cout<<(result[0]>result[1]?"Junhee is not cute!":"Junhee is cute!")<<"\n";

  return 0;
}