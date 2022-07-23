#include <iostream>

using namespace std;

int main()
{
    int K, N;
    long long mid, currLen=0, low=1, high=0, result=0, cables[10001];
    cin >> K >> N;
    for(int i=0; i<K; i++){
        cin >> cables[i];
        high = max(high, cables[i]);
    }
    while(high >= low){
        mid = (low + high)/2;
        currLen = 0;
        for(int i=0; i<K; i++){
            currLen += cables[i] / mid;
        }
        if(currLen < N) {
            high = mid-1;
        }
        else{
            low = mid+1;
            if(result < mid)  result = mid;
        }
    }
    cout << result;
}