#include <iostream>
#include <map>
using namespace std;
int a,b,c;
map<long long, long long> R;
long long recur(long long exp){
    if(R.count(exp)>0){
        return R[exp];
    }else if(exp==1){
        R[1]=a%c;
        return R[1];
    }else{
        if(exp%2==0){
            R[exp]=(recur(exp/2) * recur(exp/2))%c;
        }else{
            R[exp]=(recur(exp/2) * recur(exp/2+1))%c;
        }
        return R[exp];
    }
    
}

int main(){
    cin >> a >> b >> c;
    cout << recur(b);
}
