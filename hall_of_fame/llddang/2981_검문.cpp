#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
    if(b > a){
        int tmp = a;
        a = b;
        b = tmp;
    }
    while (b != 0){
        int r = a%b;
        a = b;
        b = r;
    }

    return a;
}

int main(){
    int N; cin >> N;
    int db[N];

    for(int i=0; i < N; i++)
        cin >> db[i];

    sort(db, db+N);

    int M = db[1] - db[0];
    for(int i=2; i < N; i++)
        M = gcd(M, db[i] - db[i-1]);

    vector<int> ans;
    for(int i=1; i*i <= M; i++){
        if(M%i == 0){
            ans.push_back(i);
            if(i != M/i) ans.push_back(M/i);
        }
    }

    sort(ans.begin(), ans.end());

    for(auto a:ans){
        if(a != 1) cout << a << " ";
    }
}
