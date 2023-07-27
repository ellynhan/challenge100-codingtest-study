#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <utility>
#include <queue>
#include <cassert>
#include <cmath>

using namespace std;

class node {
public:
    int size = 1;
    node* parent = nullptr;
};

int solution(int n, vector<vector<int>> wires) {
    vector<node> inputData(n + 1);

    queue<pair<int, int>> q;
    for (vector<int>& wire : wires)
        q.emplace(wire[0], wire[1]);

    unordered_set<int> available = { 1 };

    while (q.size()) {
        pair<int, int> edge = q.front();
        q.pop();

        int parent;
        int child;
        if (available.count(edge.first) && available.count(edge.second))
            assert(false);
        else if (available.count(edge.first)) {
            parent = edge.first;
            child = edge.second;
        }
        else if (available.count(edge.second)) {
            parent = edge.second;
            child = edge.first;
        }
        else {
            q.push(edge);
            continue;
        }

        inputData[child].parent = &inputData[parent];
        available.insert(child);
    }

    for (int i = 2; i < n + 1; i++) {
        node* index = inputData[i].parent;

        while (index != nullptr) {
            index->size++;
            index = index->parent;
        }
    }
    int answer = (1 << 31) - 1;

    for (int i = 2; i < n + 1; i++)
        answer = min(answer, abs(n - 2 * inputData[i].size));

    return answer;
}

int main(void) {
    solution(4, { {1, 2}, { 2, 3 }, { 3, 4 } });
    return 0;
}