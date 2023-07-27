#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;
using ll=long long;

int arr[8][4];
int cnt[4];

int main() {
  ioboost;

  int n, s=1, b=1;
  cin>>n;

  for(int i=0; i<6; i++) {
    cin>>arr[i][0]>>arr[i][1];
    cnt[arr[i][0]]++;
  }

  for(int i=0; i<6; i++) {
    if(cnt[arr[i][0]]==1) {
      b*=arr[i][1];
      continue;
    }

    int nn=(i+1)%6, nnn=(i+2)%6;

    if(arr[i][0]==arr[nnn][0]) s*=arr[nn][1];
  }
  cout<<(b-s)*n<<"\n";
  
  return 0;
}