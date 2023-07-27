#include <string>
#include <vector>
#include <algorithm>

#define FOR(i, j) for(int i = 0; i < j; i++)

using namespace std;

int matches[1001] = {0};
int win[1001] = {0};
int heavyWin[1001] = {0};

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    FOR(i, head2head.size()) {
        FOR(j, head2head[i].size()) {
            if (head2head[i][j] == 'W') {
                win[i]++;
                matches[i]++;
                if (weights[i] < weights[j]) {
                    heavyWin[i]++;
                }
            } else if (head2head[i][j] == 'L') {
                matches[i]++;
            }
        }
    }
    
    // 승률, 무거운복서 횟수, 자기 몸무게, 내 번호 
    vector<pair<pair<pair<double, int>, int>, int> > players;
    FOR(i, weights.size()) {
        pair<pair<pair<double, int>, int>, int> player;
        if (matches[i] == 0) player.first.first.first = 0;
        else player.first.first.first = -(double)win[i] / matches[i];
        player.first.first.second = -heavyWin[i];
        player.first.second = -weights[i];
        player.second = i + 1;
        players.push_back(player);
    }
    sort(players.begin(), players.end());
    
    FOR(i, players.size()) {
        answer.push_back(players[i].second);
    }
    
    return answer;
}