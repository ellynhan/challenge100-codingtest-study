#include <iostream>
#include <utility>
#include <list>
#include <set>

using namespace std;

int main(void) {
    int n;

    cin >> n;
    list<pair<int, int>> inputData;
    multiset<int> result;
    while (n--) {
        int n1, n2;
        cin >> n1 >> n2;
        inputData.emplace_back(n1, n2);
    }

    inputData.sort([](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first)
            return a.first < b.first;
        else
            return a.second < b.second;
        });

    for (const pair<int, int>& iter : inputData) {
        if (result.size() && iter.first >= *result.begin()) {
            result.erase(result.begin());
            result.insert(iter.second);
        }
        else {
            result.insert(iter.second);
        }

    }

    cout << result.size();

    return 0;
}