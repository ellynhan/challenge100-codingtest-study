#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, k;
queue<pair<int, int>> qp;
bool flag[200001];

void func() {
  qp.push({ n, 0 });
  flag[n]=0;

  while(!qp.empty()) {
    int p=qp.front().first, t=qp.front().second;
    qp.pop();

    if(p>100000||p<0) {
      continue;
    }

    if(p==k) {
      cout<<t<<"\n";

      break;
    }

    if(!flag[p*2]) {
      flag[p*2]=1;
      qp.push({ p*2, t+1 });
    }

    if(!flag[p+1]) {
      flag[p+1]=1;
      qp.push({ p+1, t+1 });
    }

    if(!flag[p-1]) {
      flag[p-1]=1;
      qp.push({ p-1, t+1 });
    }
  }
}

int main() {
  ioboost;

  cin>>n>>k;
  func();

  return 0;
}