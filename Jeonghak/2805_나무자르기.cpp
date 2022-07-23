#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long N, M, mid, left=0, right=0, sum=0, result=0;
    vector<int> v;
    cin >> N >> M;
    for(int i=0; i<N; i++){ 
        long long h;
        cin >> h;
        v.push_back(h);  
        right = max(right, h);
    } 
    while(left <= right){
        long long sum = 0;
        mid = (left + right) / 2;
        for(auto it = v.begin(); it != v.end(); it++){
            if((*it - mid)>0)
                sum += (*it - mid);
        }
        if(sum >= M) {
            result = max(result, mid);
            left = mid + 1;
        }
        else right = mid - 1;
    }
    cout << result;
}