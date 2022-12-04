#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct player {
  player(int n, int pp, int qq, int rr):
    no{n}, p{pp}, q{qq}, r{rr} {};
  int no;
  int p;
  int q;
  int r;
};

vector<player> input(int N) {
  vector<player> result;
  int n, p, q, r;
  while (N--) {
    cin >> n >> p >> q >> r;
    result.push_back(player(n, p, q, r));
  }
  return result;
}

bool cmp(player a, player b){
  if (a.p * a.q * a.r == b.p * b.q * b.r){
    if (a.p + a.q + a.r == b.p + b.q + b.r){
      return a.no < b.no;
    }
    else return a.p + a.q + a.r < b.p + b.q + b.r;
  }
  else return a.p * a.q * a.r < b.p * b.q * b.r;
}

int main(){
  int N;
  cin >> N;

  vector<player> players = input(N);
  sort(players.begin(), players.end(), cmp);
  for(int i = 0; i < 3; i++){
    cout << players[i].no << " ";
  }
}
