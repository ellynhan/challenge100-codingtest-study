#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1000

using namespace std;
using ll=long long;

int mat[101][101];

int main() {
  ioboost;

  int n;
  cin>>n;

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin>>mat[i][j];

      if(!mat[i][j]) {
        mat[i][j]=INF;
      }
    }
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      for(int k=0; k<n; k++) {
        mat[j][k]=min(mat[j][k], mat[j][i]+mat[i][k]);
      }
    }
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(mat[i][j]!=INF) {
        cout<<1<<" ";
      } else {
        cout<<0<<" ";
      }
    }
    cout<<"\n";
  }
  return 0;
}