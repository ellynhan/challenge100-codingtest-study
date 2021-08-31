#include <iostream>
#include <functional>
#include <list>
#include <deque>
#include <queue>

using namespace std;

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;

    priority_queue<int, deque<int>, greater<int>> inputData;
    
    list<int> data;
    
    cin >> n;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;

        if (a == 0) {
            if (inputData.empty())
                cout << 0 << '\n';
            else{
                cout << inputData.top() << '\n';
                inputData.pop();
            }
        }
        else{
            inputData.push(a);
        }
    }
    
    return 0;
}