#include <bits/stdc++.h>
using namespace std;

int n;
int arr[15];
int num[15];
bool isused[15];

void func(int k, int st){
  if(k == 6){
      for(int i = 0; i < 6; i++)
        cout << arr[i] << " ";
      cout << "\n";
    return;
  }

  for(int i = st; i < n; i++){
    if(!isused[i]){
      arr[k] = num[i];
      isused[i] = 1;
      func(k+1, i);
      isused[i] = 0;
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(1){
    cin >> n;
    if(n == 0) break;
    for(int i = 0; i < n; i++)
      cin >> num[i];
    sort(num, num+n);
    func(0, 0);
    cout << "\n";
    fill(num, num+n, 0);
    fill(arr, arr+n, 0);
  }
}

/*
#include <bits/stdc++.h>
using namespace std;

int k, s;
int arr[15];
int num[15];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(1){
    cin >> k;
    if(!k) break;
    for(int i = 0; i < k; i++) cin >> arr[i];
    fill(num+6, num+k, 1);

    do{
      for(int i = 0; i < k; i++)
        if(!num[i]) cout << arr[i] << " ";
      cout << "\n";
    }while(next_permutation(num, num+k));
    cout << "\n";
  }
}
*/
