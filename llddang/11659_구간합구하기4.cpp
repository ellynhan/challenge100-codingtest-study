#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, tmp;
    cin >> N >> M;

    vector<int> db;
    int sum = 0;
    db.push_back(0);
    while(N--){
        cin >> tmp;
        sum += tmp;
        db.push_back(sum);
    }

    while(M--){
        int s, e;
        cin >> s >> e;
        int result = db[e] - db[s-1];
        cout << result << "\n";
    }
}
