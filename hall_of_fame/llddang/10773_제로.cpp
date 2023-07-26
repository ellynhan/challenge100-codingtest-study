#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    stack <int> db;
    int N; cin >> N;

    for(int i=0; i<N; i++){
        int tmp; cin >> tmp;
        if(tmp == 0) db.pop();
        else db.push(tmp);
    }

    int sum = 0;
    while (!db.empty()) {
        sum += db.top();
        db.pop();
    }

    cout << sum;
}
