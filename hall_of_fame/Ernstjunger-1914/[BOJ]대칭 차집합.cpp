#include <bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;
using ll=long long;

int asz, bsz, res;
int a[200001], b[200001];
map<int, int> mi;

int main() {
  ioboost;

  cin>>asz>>bsz;

  for(int i=0; i<asz; i++) cin>>a[i];
  for(int i=0; i<bsz; i++) cin>>b[i];

  for(int i=0; i<asz; i++) mi[a[i]]++;
  for(int i=0; i<bsz; i++) {
    if(mi[b[i]]) res++;
  }

  cout<<asz+bsz-res*2<<"\n";
  
  return 0;
}