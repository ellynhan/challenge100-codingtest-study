#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> db;
vector<int> num;
int N;

void check(int curr, int plu, int minu, int multi, int mod, int result){
    if(curr == N){
        db.push_back(result);
        return;
    }
    if(plu   != 0) check(curr+1, plu-1, minu, multi, mod, result+num[curr]);
    if(minu  != 0) check(curr+1, plu, minu-1, multi, mod, result-num[curr]);
    if(multi != 0) check(curr+1, plu, minu, multi-1, mod, result*num[curr]);
    if(mod   != 0) check(curr+1, plu, minu, multi, mod-1, result/num[curr]);
}

int main() {
    cin >> N;
    int tmp;
    for(int i=0; i<N; i++){
        cin >> tmp;
        num.push_back(tmp);
    }
    int plu, minu, multi, mod;
    cin >> plu >> minu >> multi >> mod;

    check(1, plu, minu, multi, mod, num[0]);

    sort(db.begin(), db.end());
    cout << db[db.size()-1] << "\n";
    cout << db[0];

}
