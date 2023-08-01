#include <iostream>
#include <vector>
using namespace std;

void Combination(int,int,int);

vector<int> vec;

int main(){
    int N, R; cin >> N >> R;
    for(int i=1; i<=N-R+1; i++){
        vec.push_back(i);
        Combination(N,R,R);
        vec.pop_back();
    }
}

void Combination(int N,int R, int r){
    if(r==1){
        for(auto a:vec)
            cout << a << " ";
        cout << "\n";
        return;
    }
    
    vec.push_back(vec.back()+1);
    Combination(N, R, r-1);

    for(int i=vec.back()+1; i <= N-r+2;i++){
        vec.pop_back();
        vec.push_back(i);
        Combination(N, R, r-1);
    }
    vec.pop_back();
    return;
}
