#include <iostream>

using namespace std;

int main(void){
    cin.tie(0);
    int L,P,V,ans,pcase=1;

    cin >> L >> P >> V;

    while(L||P||V){
        if(V%P < L)
            ans = (V/P)*L + V%P;
        else
            ans = (V/P)*L + L;
    
        cout << "Case "<<pcase<<": "<<ans<<"\n";
        pcase++;
        cin >> L >> P >> V;
    }

    return 0;
}
