#include <string>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;

    stack<pair<int, int>> dfs; // now, count
    dfs.emplace(0, 0);

    while (dfs.size()) {
        int now = dfs.top().first;
        int count = dfs.top().second;
        dfs.pop();

        if (count == numbers.size()) {
            if (now == target)
                answer++;
            continue;
        }
        dfs.emplace(now - numbers[count], count + 1);
        dfs.emplace(now + numbers[count], count + 1);
    }


    return answer;
}