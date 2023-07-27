#include <string>
#include <vector>
#include <algorithm>

#define FOR(i, j) for(int i = 0; i < j; i++)

using namespace std;

int N;
int M;
bool isUse[500][500][4] = {0};
vector<int> answer;

void lightning(int n, int m, int dir, int depth, vector<string> &grid)
{
    if (isUse[n][m][dir]) {
        answer.push_back(depth);
        return;
    }
    isUse[n][m][dir] = true;
    if (grid[n][m] == 'L') {
        if (dir == 0) {
            lightning(n, (m + 1) % M, (dir + 1) % 4, depth + 1, grid);
        } else if (dir == 1) {
            lightning((n + N - 1) % N, m, (dir + 1) % 4, depth + 1, grid);
        } else if (dir == 2) {
            lightning(n, (m + M - 1) % M, (dir + 1) % 4, depth + 1, grid);
        } else if (dir == 3) {
            lightning((n + 1) % N, m, (dir + 1) % 4, depth + 1, grid);
        }
    } else if (grid[n][m] == 'R') {
        if (dir == 0) {
            lightning(n, (m + M - 1) % M, (dir + 3) % 4, depth + 1, grid);
        } else if (dir == 1) {
            lightning((n + 1) % N, m, (dir + 3) % 4, depth + 1, grid);
        } else if (dir == 2) {
            lightning(n, (m + 1) % M, (dir + 3) % 4, depth + 1, grid);
        } else if (dir == 3) {
            lightning((n + N - 1) % N, m, (dir + 3) % 4, depth + 1, grid);
        }
    } else if (grid[n][m] == 'S') {
        if (dir == 0) {
            lightning((n + 1) % N, m, dir, depth + 1, grid);
        } else if (dir == 1) {
            lightning(n, (m + 1) % M, dir, depth + 1, grid);
        } else if (dir == 2) {
            lightning((n + N - 1) % N, m, dir, depth + 1, grid);
        } else if (dir == 3) {
            lightning(n, (m + M - 1) % M, dir, depth + 1, grid);
        }
    }
}

vector<int> solution(vector<string> grid)
{
    N = grid.size();
    M = grid[0].size();
    
    FOR(n, N) {
        FOR(m, M) {
            FOR(dir, 4) {
                if (!isUse[n][m][dir]) {
                    lightning(n, m, dir, 0, grid);
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}