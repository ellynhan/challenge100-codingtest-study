#include <iostream>
#include <vector>
using namespace std; 
#define ll long long
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define mod 1000000007

vvll multiMat(vvll a, vvll b){
    vvll ret(2);
    for(int i=0; i<2; i++){
        ret[i].resize(2);
        for(int j=0; j<2; j++){
            ret[i][j] = 0;
            for(int k=0; k<2; k++){
                ret[i][j] += a[i][k]*b[k][j];
                ret[i][j] %= mod;
            }
        }
    }
    return ret;
}

vvll divideConquer(ll n){
    if(n==1) return {{0,1},{1,1}};
    vvll tmp;
    if(n%2==0){
        tmp = divideConquer(n/2);
        return multiMat(tmp, tmp);
    }else{
        tmp = divideConquer(n-1);
        return multiMat({{0,1},{1,1}},tmp);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    long long n;
    cin >> n;
    vvll answer;
    if(n==0){
        cout<< 0;
    }else{
        answer = divideConquer(n);
        cout<<answer[1][0];
    }
}
