#include <string>
#include <vector>
#include <list>
#include <queue>
using namespace std;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0 ,-1, 0 };
class pos {
public:
    int x;
    int y;
    pos(int x = 0, int y = 0) : x(x), y(y) {}
};

class puzzle {
public:
    int length;
    int size;
    int usable = true;
    vector<vector<bool>> position;

    puzzle rotate() {
        puzzle newPuzzle;
        newPuzzle.size = size;
        newPuzzle.length = length;
        newPuzzle.position = vector<vector<bool>>(length, vector<bool>(length));

        int minX = 7, minY = 7;
        for (int i = 0; i < position.size(); i++) {
            for (int j = 0; j < position.size(); j++) {
                if (position[i][j]) {
                    newPuzzle.position[length - 1 - j][i] = true;
                    if (length - 1 - j < minX)
                        minX = length - 1 - j;
                    if (i < minY)
                        minY = i;
                }
            }
        }
        for (int i = 0; i < newPuzzle.position.size(); i++) {
            for (int j = 0; j < newPuzzle.position.size(); j++) {
                if (newPuzzle.position[i][j]){
                    newPuzzle.position[i][j] = false;
                    newPuzzle.position[i- minX][j - minY] = true;
                }
                    
            }
        }
        
        return newPuzzle;
    }

    bool operator ==(puzzle other) const {
        if (length != other.length || size != other.size)
            return false;
        if (position == other.position)
            return true;
        
        for (int i = 0; i < 3; i++) {
            other = other.rotate();
            if (position == other.position)
                return true;
        }
        return false;
    }
};

bool isValid(const vector<vector<int>>& table, int x, int y, bool puzzle = true) {
    if (x < 0 || x >= table.size())
        return false;
    if (y < 0 || y >= table.size())
        return false;
    if (puzzle)
        return table[x][y];
    else
        return !table[x][y];
}
void inputPuzzle(vector<vector<int>>& table, list<puzzle>& puzzleList) {
    queue<pos> bfs;
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table.size(); j++) {
            if (table[i][j]) {
                bfs.push(pos(i, j));
                int minX = 51, minY = 51;
                int maxX = 0, maxY = 0;
                int size = 0;
                list<pos> puzzlePosList;
                while (bfs.size()) {
                    int x = bfs.front().x;
                    int y = bfs.front().y;
                    bfs.pop();
                    
                    if(!table[x][y])
                        continue;
                    
                    table[x][y] = 0;
                    size++;
                    puzzlePosList.push_back(pos(x, y));

                    if (x < minX)
                        minX = x;
                    if (y < minY)
                        minY = y;
                    if (x > maxX)
                        maxX = x;
                    if (y > maxY)
                        maxY = y;
                    for (int i = 0; i < 4; i++)
                        if (isValid(table, x + dx[i], y + dy[i]))
                            bfs.push(pos(x + dx[i], y + dy[i]));

                }
                puzzle newPuzzle;
                newPuzzle.size = size;
                newPuzzle.length = (maxY - minY) > (maxX - minX) ? (maxY - minY) + 1 : (maxX - minX) + 1;

                newPuzzle.position = vector<vector<bool>>(newPuzzle.length, vector<bool>(newPuzzle.length));
                for (const pos& iter : puzzlePosList)
                    newPuzzle.position[iter.x - minX][iter.y - minY] = true;
                puzzleList.push_back(newPuzzle);
            }
        }
    }
    // // 퍼즐 출력
    // for(const puzzle& iter : puzzleList){
    //     cout << iter.size << endl;
    //     for(int i = 0; i< iter.position.size(); i++){
    //         for(int j = 0; j< iter.position.size(); j++){
    //             cout << static_cast<int>(iter.position[i][j]) << " ";
    //         }cout << endl;
    //     }
    //     cout << endl;
    // }
}
int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    list<puzzle> puzzleList;
    inputPuzzle(table, puzzleList);
    int answer = 0;

    queue<pos> bfs;
    for (int i = 0; i < game_board.size(); i++) {
        for (int j = 0; j < game_board.size(); j++) {
            if (!game_board[i][j]) {
                bfs.push(pos(i, j));
                int minX = 51, minY = 51;
                int maxX = 0, maxY = 0;
                int size = 0;
                list<pos> tablePosList;
                while (bfs.size()) {
                    int x = bfs.front().x;
                    int y = bfs.front().y;
                    bfs.pop();
                    if (game_board[x][y])
                        continue;
                    game_board[x][y] = 1;
                    size++;
                    tablePosList.push_back(pos(x, y));

                    if (x < minX)
                        minX = x;
                    if (y < minY)
                        minY = y;
                    if (x > maxX)
                        maxX = x;
                    if (y > maxY)
                        maxY = y;
                    for (int i = 0; i < 4; i++)
                        if (isValid(game_board, x + dx[i], y + dy[i], false))
                            bfs.push(pos(x + dx[i], y + dy[i]));

                }
                puzzle newPuzzle;
                newPuzzle.size = size;
                newPuzzle.length = (maxY - minY) > (maxX - minX) ? (maxY - minY) + 1 : (maxX - minX) + 1;

                newPuzzle.position = vector<vector<bool>>(newPuzzle.length, vector<bool>(newPuzzle.length));
                for (const pos& iter : tablePosList)
                    newPuzzle.position[iter.x - minX][iter.y - minY] = true;

                for (puzzle& iter : puzzleList)
                    if (iter.usable && newPuzzle == iter) {
                        answer += newPuzzle.size;
                        iter.usable = false;
                        break;
                    }
            }
        }
    }

    return answer;
}