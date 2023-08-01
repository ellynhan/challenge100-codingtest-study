#include <iostream>
#include <queue>
#define ll long long
using namespace std;

int N;
struct INFO{ll a, b, r1, r2;};
queue<INFO> info;
ll rati[10] = {0, };

ll gcd(ll a, ll b){
  ll mi = min(a, b);
  ll ma = max(a, b);

  while(mi != 0){
    ll c = ma % mi;
    ma = mi;
    mi = c;
  }
  return ma;
}

ll lcd(ll a, ll b){
  return a * b / gcd(a, b);
}

int main(){
  cin >> N;
  ll a, b, r1, r2, r3, g, l;
  for(int i=0; i<N-1; i++){
    cin >> a >> b >> r1 >> r2;
    info.push({a, b, r1, r2});
  }

  while(!info.empty()){
    INFO tmp = info.front(); info.pop();
    g = gcd(tmp.r1, tmp.r2);
    r1 = tmp.r1 / g;
    r2 = tmp.r2 / g;

    if(info.size() == N - 2){
      rati[tmp.a] = r1;
      rati[tmp.b] = r2;
    } else if(rati[tmp.a] != 0){
      r3 = rati[tmp.a];
      l = lcd(r3, r1);
      for(int i=0; i<N; i++) rati[i] = rati[i] * l / r3;
      rati[tmp.b] = r2 * l / r1;
    } else if(rati[tmp.b] != 0){
      r3 = rati[tmp.b];
      l = lcd(r3, r2);
      for(int i=0; i<N; i++) rati[i] = rati[i] * l / r3;
      rati[tmp.a] = r1 * l / r2;
    } else info.push(tmp);
  }

  for(int i=0; i<N; i++) cout << rati[i] << " ";
}
