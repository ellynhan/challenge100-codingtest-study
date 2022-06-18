#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int upDir[4][2] = { {0,1},{-1,0}, {0,-1}, {1,0} };
const int downDir[4][2] = { {0,1},{1,0}, {0,-1}, {-1,0} };

const int delta[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

int r, c, t;
pair<int, int> up;
pair<int, int> down;

bool isValid(int x, int y) {
    if (x < 0 || x >= r || y < 0 || y >= c) {
        return false;
    }

    if (x == up.first && y == up.second)
        return false;

    if (x == down.first && y == down.second)
        return false;

    return true;
}

class Room {
public:
    int now = 0;
    int input = 0;
    int output = 0;

};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> t;

    vector< vector<Room> > inputData(r, vector<Room>(c));

    bool findmachine = false;


    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> inputData[i][j].now;
            if (!findmachine && inputData[i][j].now == -1) {
                up = pair<int, int>(i, j);
                down = pair<int, int>(i + 1, j);
                findmachine = true;
            }
        }
    }
    inputData[up.first][up.second].now = 0;
    inputData[down.first][down.second].now = 0;

    for (int time = 0; time < t; time++) {

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int mess = inputData[i][j].now / 5;

                for (int j2 = 0; j2 < 4; j2++) {
                    int x = i + delta[j2][0];
                    int y = j + delta[j2][1]; 

                    if (isValid(x, y)) {
                        inputData[x][y].input += mess;
                        inputData[i][j].output += mess;
                    }
                }

            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                inputData[i][j].now += inputData[i][j].input - inputData[i][j].output;
                inputData[i][j].input = 0;
                inputData[i][j].output = 0;
            }
        }


        int x = up.first;
        int y = up.second;
        Room temp = Room();

        // 위쪽 공기청정기
        for (int i = 0; i < 4; i++) {
            x += upDir[i][0];
            y += upDir[i][1];

            while (isValid(x, y)) {
                Room temp2 = Room(inputData[x][y]);
                inputData[x][y] = temp;
                temp = temp2;
                x += upDir[i][0];
                y += upDir[i][1];
            }
            x -= upDir[i][0];
            y -= upDir[i][1];
        }

        x = down.first;
        y = down.second;
        temp = Room();

        // 아래쪽 공기청정기
        for (int i = 0; i < 4; i++) {
            x += downDir[i][0];
            y += downDir[i][1];

            while (isValid(x, y)) {
                Room temp2 = Room(inputData[x][y]);
                inputData[x][y] = temp;
                temp = temp2;
                x += downDir[i][0];
                y += downDir[i][1];
            }
            x -= downDir[i][0];
            y -= downDir[i][1];
        }

        inputData[up.first][up.second].now = 0;
        inputData[down.first][down.second].now = 0;

    }

    int ans = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            ans += inputData[i][j].now;

    cout << ans;

    return 0;
}