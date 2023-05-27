#include <algorithm>
#include <iostream>
using namespace std;

int arr[1000];

int main(){
    int N; cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    
    sort(arr, arr+N);
    
    long long time = 0;
    for(int i=0; i<N; i++) time += arr[i] * (N-i);
    
    cout << time;
}
