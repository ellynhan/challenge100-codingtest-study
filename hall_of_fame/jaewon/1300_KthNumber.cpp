#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    
    int low = 1, high = k;
    int answer = 0;
    while(low<=high){
        int cnt = 0;
        int mid = (low+high)/2;
        for(int i=1; i<=n; i++){
            cnt += min(mid/i, n);
        }
        if(cnt < k){
            low = mid +1;
        }else{
            high = mid -1;
            answer = mid;
        }
    }
    cout<<answer;
}
