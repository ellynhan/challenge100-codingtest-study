#include <iostream>
#include <cmath>
#define MAX 1048577
using namespace std;

void merge(int start, int mid, int end, int* data){
  int i = start;
  int j = mid+1;
  int k = start;
  int sorted[MAX];

  while(k < end+1){
    if(i == mid+1){
      sorted[k++] = data[j++];
      continue;
    } else if(j == end+1){
      sorted[k++] = data[i++];
      continue;
    }

    if(data[i] < data[j]){
      sorted[k++] = data[i++];
    } else {
      sorted[k++] = data[j++];
    }
  }

  for(i=start; i<end+1; i++){
    data[i] = sorted[i];
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N; cin >> N;
  int i;
  int data[MAX];
  for(i=0; i<N; i++){
    cin >> data[i];
  }
  int k; cin >> k;

  int n = N;
  int s, e, m, interval;
  while(n != k){
    n /= 2;
    s = 0;
    interval = N/n;
    while(1){
      e = s + interval - 1;
      m = (s + e) / 2;
      if(e >= N) break;
      merge(s, m, e, data);
      s = e + 1;
    }
  }

  for(i=0; i<N; i++){
    cout << data[i] << " ";
  }
}
