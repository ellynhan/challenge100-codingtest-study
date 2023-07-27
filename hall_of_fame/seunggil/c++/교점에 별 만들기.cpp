#include <string>
#include <vector>
#include <cmath>
#include <list>
#include <cassert>
#include <iostream>

using namespace std;

struct pos {
    long long x;
    long long y;
    pos(long long x, long long y) : x(x), y(y) {}
};

void posSort(vector<pos>& posList, vector<string>& ans) {
    long long minx = (1LL << 63) - 1;
    long long miny = (1LL << 63) - 1;
    long long maxx = (1LL << 63);
    long long maxy = (1LL << 63);

    for (pos& iter : posList) {
        minx = min(iter.x, minx);
        miny = min(iter.y, miny);
        maxx = max(iter.x, maxx);
        maxy = max(iter.y, maxy);
    }

    int sizeY = maxy - miny + 1;
    int sizeX = maxx - minx + 1;

    for (pos& iter : posList) {
        iter.x = iter.x - minx;
        iter.y = iter.y - miny;
        assert(iter.x >= 0 && iter.y >= 0);
    }
    ans = vector<string>(sizeY, string(sizeX, '.'));

    for (pos& iter : posList)
        ans[sizeY - 1 - iter.y][iter.x] = '*';

}

vector<string> solution(vector<vector<int>> line) {
    vector<pos> meetPos;

    for (int i = 0; i < line.size(); i++) {
        for (int j = 0; j < line.size(); j++) {
            long long a = line[i][0];
            long long b = line[i][1];
            long long e = line[i][2];
            long long c = line[j][0];
            long long d = line[j][1];
            long long f = line[j][2];
            long long adbc = a * d - b * c;
            if (adbc == 0)
                continue;

            double x = static_cast<double>(b * f - e * d) / adbc;
            double y = static_cast<double>(e * c - a * f) / adbc;

            long long convertX = static_cast<long long>(x);
            long long convertY = static_cast<long long>(y);

            if (x == convertX && y == convertY) {
                meetPos.emplace_back(convertX, convertY);
            }
        }
    }

    vector<string> answer;
    posSort(meetPos, answer);

    return answer;
}