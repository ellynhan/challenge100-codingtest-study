#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;
using ll=long long;

int main() {
  ioboost;

  int n, m;
  cin>>n;

  vector<int> card(n, 0);

  for(int i=0; i<n; i++) cin>>card[i];
  sort(card.begin(), card.end());
  cin>>m;

  vector<int> chk(m, 0), res(m, 0);

  for(int i=0; i<m; i++) {
    cin>>chk[i];
    int l=0, h=n-1;

    while(l<=h) {
      int mid=(l+h)/2;

      if(card[mid]==chk[i]) {
        res[i]++;
        break;
      } else if(card[mid]<chk[i]) {
        l=mid+1;
      } else if(card[mid]>chk[i]) {
        h=mid-1;
      }
    }
  }

  for(int i=0; i<m; i++) {
    cout<<res[i]<<" ";
  }
  cout<<"\n";
  
  return 0;
}