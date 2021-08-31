#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

int getLength(const pair<int, int> a, const pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (vector<string>& iter : places) {
        vector<pair<int, int>> user;
        vector<vector<int>> place(5, vector<int>(5));
        for (int i = 0; i < iter.size(); i++)
            for (int j = 0; j < iter[i].size(); j++)
                switch (iter[i][j]) {
                case 'P':
                    place[i][j] = 1;
                    user.emplace_back(i, j);
                    break;
                case 'O':
                    place[i][j] = 0;
                    break;
                case 'X':
                    place[i][j] = -1;
                    break;
                }


        // for(int i =0; i< place.size(); i++){
        //     for(int j = 0; j < place[i].size(); j++)
        //         cout << place[i][j] << " ";
        //     cout << endl;
        // }
        if (user.empty()) {
            answer.push_back(1);
            continue;
        }
        bool finished = false;
        for (int i = 0; i < static_cast<int>(user.size()) - 1; i++) {
            for (int j = i + 1; j < static_cast<int>(user.size()); j++) {
                int lens = getLength(user[i], user[j]);
                if (lens == 1) {
                    finished = true;
                    break;
                }
                else if (getLength(user[i], user[j]) == 2) {
                    if (user[i].first == user[j].first) {
                        if (place[user[i].first][(user[i].second + user[j].second) / 2] != -1) {
                            finished = true;
                            break;
                        }
                    }
                    else if (user[i].second == user[j].second) {
                        if (place[(user[i].first + user[j].first) / 2][user[i].second] != -1) {
                            finished = true;
                            break;
                        }
                    }
                    else if (place[user[i].first][user[j].second] != -1 || place[user[j].first][user[i].second] != -1) {
                        finished = true;
                        break;
                    }
                }
            }

            if (finished) {
                answer.push_back(0);
                break;
            }

        }

        if (!finished)
            answer.push_back(1);
    }

    return answer;
}