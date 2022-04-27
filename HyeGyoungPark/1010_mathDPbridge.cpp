#include <iostream>

using namespace std;

long long comb[30][30] = {0,};

long long combination(int n, int r)
{
    if(n == r || r == 0) 
        return 1; 
        
    if(comb[n][r]!=0){
        return comb[n][r];
    }
    else
        comb[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
        return comb[n][r];
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t,n,m;
    
    cin >> t;
    
    for(int i=0; i<t; i++){
        cin >> n >> m;
        if(n>m-n) n = m-n;
        
        cout << combination(m,n) << "\n";
    }

    return 0;

}
