#include <vector>
#include <utility>
#include <iostream>
#include <list>

using namespace std;

int main(void) {
    list<pair<int, int>> inputData;
    int N, a, b;

    cin >> N;

    while (N > 0) {
        cin >> a >> b;
        inputData.emplace_back(a, b);
        N--;
    }
    inputData.sort([](pair<int, int> a, pair<int, int>b) {
        if (a.second != b.second)
            return a.second < b.second;
        else
            return a.first < b.first;
        });

    int answer = 0;
    int use = -1;

    for (pair<int, int> iter : inputData)
        if (use <= iter.first) {
            answer++;
            use = iter.second;
        }
    
    cout << answer << endl;

    return 0;
}