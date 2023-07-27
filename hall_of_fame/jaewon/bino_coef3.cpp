#include <iostream>
#include <map>
using namespace std; 
#define ll long long
#define p 1000000007
map<ll,ll> m;
ll mul(ll a, int b){
    if(b==1){
        return a;
    }
    if(m.count(b)>0){
        return m[b];
    }else if(b%2==0){
        m[b] = (mul(a,b/2)%p)*(mul(a,b/2)%p);
    }else{
        m[b] = (mul(a,b/2)%p)*(mul(a,b/2+1)%p);
    }
    return m[b];
}

int main(void) {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    int N,K;
    cin >> N >> K;
    ll n=1;
    ll n_k=1;
    ll k=1;
    for(int i=1; i<=N; i++){
        n*=i;
        if(i<=K){
            k*=i;
        }
        if(i<=N-K){
            n_k*=i;
        }
        n%=p;
        k%=p;
        n_k%=p;
    }
    ll nkk = (n_k*k)%p;
    ll nkkp = mul(nkk,p-2)%p;
    cout<<(n*nkkp)%p;
}
