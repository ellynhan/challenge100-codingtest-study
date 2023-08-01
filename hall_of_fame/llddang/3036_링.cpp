#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b > a){
        int tmp = a;
        a = b;
        b = tmp;
    }
    while(b != 0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    int N; cin >> N;
    int stand; cin >> stand;
    for(int i=1; i<N; i++){
        int tmp; cin >> tmp;
        int g = gcd(tmp, stand);
        cout << stand / g << "/" << tmp / g << "\n";
    }
}
