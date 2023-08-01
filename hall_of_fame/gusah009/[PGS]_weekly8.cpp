#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    FOR(s, sizes.size()) {
        if (sizes[s][0] < sizes[s][1]) {
            swap(sizes[s][0], sizes[s][1]);
        }
    }
    int maximum1 = -1, maximum2 = -1;
    FOR(s, sizes.size()) {
        maximum1 = max(maximum1, sizes[s][0]);
        maximum2 = max(maximum2, sizes[s][1]);
    }
    answer = maximum1 * maximum2;
    return answer;
}