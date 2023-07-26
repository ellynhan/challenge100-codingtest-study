#include <iostream>
#define boost ios::sync_with_stdio(false), cin.tie(0)
using namespace std;
int main(){
    boost;
    int n,s;
    cin >> n >> s;
    int* arr = new int[n+1];
    arr[0]=0; //부분합에서 이 부분을 쉽게 놓칠 수 있다.
    for(int i=1; i<n+1; i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    int i=0, j=1, min=100001;
    while(j<n+1){
        if(j==i && j<n){
            j++;
        }
        if(arr[j]-arr[i]<s){
            j++;
        }else{
            if(min > j-i) min = j-i;
            i++;
        }
    }

    if(min == 100001){
        min = 0;
    }
    cout<<min;
}
