#include <iostream>
#include <cmath>
#define ll long long

using namespace std;

int main()
{
    int N, idx, jdx; 
    cin >> N >> idx >> jdx;
    
    ll cnt = 0;
    
    while(idx != 0 || jdx != 0){
        N--;
        if(idx < pow(2, N) && jdx >= pow(2, N)){ // 2번째 바닥
            cnt += pow(2, N) * pow(2, N);
            jdx -= pow(2, N);
        } else if(idx >= pow(2, N) && jdx < pow(2, N)) { // 3번째 바닥
            cnt += pow(2, N) * pow(2, N) * 2;
            idx -= pow(2, N);
        } else if(idx >= pow(2, N) && jdx >= pow(2, N)){ // 4번째 바닥
            cnt += pow(2, N) * pow(2, N) * 3;
            idx -= pow(2, N);
            jdx -= pow(2, N);
        }
    }
    cout << cnt;
}
