#include <cstdio>
#include <list>
#include <utility>
using namespace std;

int main(void) {

    list<pair<int, int>> inputData;
    int n;
    scanf("%d", &n);
    while (n--) {
        int x, y;
        scanf("%d %d", &x, &y);
        inputData.push_back({ x, y });
    }

    inputData.sort([](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second)
            return a.second < b.second;
        else
            return a.first < b.first;
        });

    for (const pair<int, int>& iter : inputData) 
        printf("%d %d\n", iter.first, iter.second);

    return 0;
}