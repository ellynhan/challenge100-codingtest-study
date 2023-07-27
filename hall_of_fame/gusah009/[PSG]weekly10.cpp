#include <iostream>
#include <string>
#include <vector>

#define FOR(i, j) for(long long i = 0; i < j; i++)
#define INF 1987654321198765

using namespace std;

// bool board[3000][3000] = {0};
vector<pair<long long, long long> > ans;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    FOR (i, line.size()) {
        long long a1 = line[i][0];
        long long b1 = line[i][1];
        long long c1 = line[i][2];
        for (long long j = i + 1; j < line.size(); j++) {
            if (i != j) {
                long long a2 = line[j][0];
                long long b2 = line[j][1];
                long long c2 = line[j][2];
                
                long long tmp1 = b1 * c2 - b2 * c1;
                long long tmp2 = a1 * b2 - a2 * b1;
                long long tmp3 = c1 * a2 - c2 * a1;
                // cout << tmp1 << ' ' << tmp2 << ' ' << tmp3 << '\n';
                if (tmp2 != 0 && abs(tmp1) % abs(tmp2) == 0 && abs(tmp3) % abs(tmp2) == 0) {
                    // cout << i << ' ' << j << '\n';
                    // cout << tmp1 / tmp2 << ' ' << tmp3 / tmp2 << '\n' << '\n';
                    ans.push_back({tmp1 / tmp2, tmp3 / tmp2});
                }
            }
        }
    }
    
    long long xMin = INF;
    long long yMin = INF;
    long long xMax = -INF;
    long long yMax = -INF;
    FOR(i, ans.size()) {
        xMin = min(xMin, ans[i].first);
        yMin = min(yMin, ans[i].second);
        xMax = max(xMax, ans[i].first);
        yMax = max(yMax, ans[i].second);
    }
    xMax -= xMin;
    yMax -= yMin;
    vector < vector <bool> > board(yMax + 1, vector <bool>(xMax + 1, 0));
    // cout << xMin << ' ' << yMin << '\n';
    // cout << xMax << ' ' << yMax << '\n';
    FOR(i, ans.size()) {
        board[ans[i].second - yMin][ans[i].first  - xMin] = true;
    }
    
    for(long long i = yMax; i >= 0; i--) {
        string tmp = "";
        FOR(j, xMax + 1) {
            tmp += board[i][j] ? '*' : '.';
        }
        answer.push_back(tmp);
    }
    return answer;
}