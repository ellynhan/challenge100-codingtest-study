#include <string>
#include <vector>

using namespace std;

#define MAX_LINE 5

int visitBitMap;
bool distanceWatcher;

bool checkPlace(vector<string>);
void initMap(int,int);
void dfs(vector<string>, int, int, int);

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;

    for (const auto &i : places)
    {
        if (checkPlace(i))
        {
            answer.push_back(1);
        }
        else
        {
            answer.push_back(0);
        }
    }

    return answer;
}

bool checkPlace(vector<string> place)
{

    for (int row = 0; row < MAX_LINE; row++)
    {
        for (int col = 0; col < MAX_LINE; col++)
        {
            if (place[row][col] == 'P')
            {
                initMap(row,col);

                dfs(place, row, col, 0);
                if (!distanceWatcher)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

void initMap(int row, int col)
{
    distanceWatcher = true;
    visitBitMap = 0;
}

void dfs(vector<string> place, int row, int col, int depth)
{
    if (!distanceWatcher)
        return;

    if (depth > 2)
        return;

    if ((row < 0 || row > MAX_LINE - 1) || (col < 0 || col > MAX_LINE - 1))
        return;

    int visitMask = 1 << (row * MAX_LINE + col);

    if (visitBitMap & visitMask)
        return;
    else
        visitBitMap |= visitMask;

    if (place[row][col] == 'O' || depth == 0)
    {
        dfs(place, row + 1, col, depth + 1);
        dfs(place, row, col + 1, depth + 1);
        dfs(place, row - 1, col, depth + 1);
        dfs(place, row, col - 1, depth + 1);
    }

    if (place[row][col] == 'X')
        return;

    if (place[row][col] == 'P' && depth != 0)
    {
        distanceWatcher = false;
        return;
    }
}

