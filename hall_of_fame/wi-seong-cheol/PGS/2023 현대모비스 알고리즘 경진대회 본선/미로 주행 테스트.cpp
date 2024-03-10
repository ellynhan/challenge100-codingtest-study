//
//  미로 주행 테스트.cpp
//  main
//
//  Created by wi_seong on 2/19/24.
//

// 시간복잡도: O(nlogn)
// 최악시간: 2,500,000
// 난이도: Level 5
// Timer: 2h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/214295

#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <algorithm>

using namespace std;

static inline long long min(long long a, long long b) {
    return a < b ? a : b;
}

static inline long long max(long long a, long long b) {
    return a > b ? a : b;
}

struct Area {
    int minx;
    int miny;
    int maxx;
    int maxy;

    Area() {}

    Area(int minx, int miny, int maxx, int maxy) :
        minx(minx),
        miny(miny),
        maxx(maxx),
        maxy(maxy)
    { }

    inline operator bool() const {
        return minx <= maxx && miny <= maxy;
    }

    inline bool operator !() const {
        return !(operator bool());
    }
};

static Area clipArea(const Area& a, int x, int y, int d, int m) {
    long long ix = x - y + m;
    long long iy = x + y;
    return Area(
        max(a.minx, ix - d),
        max(a.miny, iy - d),
        min(a.maxx, ix + d),
        min(a.maxy, iy + d)
    );
}

#define GRID_FIT(x, y, m)   (((x) - (m) + (y)) & 1)

static long long getOutGridCount(int x, int y, int d, int m) {
    int t = GRID_FIT(x, y, m);
    d = (d + 1 - t) / 2;
    return (long long)(d + t) * d;
}

static long long getGridCount(Area a, int n, int m) {
    //lefttop
    if (a.maxy < m && a.minx < m - a.maxy) {
        a.minx = m - a.maxy;
        if (a.minx > a.maxx) return 0;
    }
    if (a.maxx < m && a.miny < m - a.maxx) {
        a.miny = m - a.maxx;
        if (a.miny > a.maxy) return 0;
    }
    //righttop
    if (a.maxy < n && a.maxx - m > a.maxy) {
        a.maxx = m + a.maxy;
        if (a.minx > a.maxx) return 0;
    }
    if (a.minx > m && a.miny < a.minx - m) {
        a.miny = a.minx - m;
        if (a.miny > a.maxy) return 0;
    }
    //leftbottom
    if (a.miny > m && a.minx < a.miny - m) {
        a.minx = a.miny - m;
        if (a.minx > a.maxx) return 0;
    }
    if (a.maxx < n && a.maxy - m > a.maxx) {
        a.maxy = m + a.maxx;
        if (a.miny > a.maxy) return 0;
    }
    //rightbottom
    if (a.miny > n && a.maxx > n + m - (a.miny - n)) {
        a.maxx = n + m - (a.miny - n);
        if (a.minx > a.maxx) return 0;
    }
    if (a.minx > n && a.maxy > n + m - (a.minx - n)) {
        a.maxy = n + m - (a.minx - n);
        if (a.miny > a.maxy) return 0;
    }

    if (!a) return 0;

    int t = GRID_FIT(a.minx, a.miny, m);

    int w = a.maxx - a.minx + 1;
    int rw = w >> 1;
    int lw = w - rw;
    long long lh = (a.maxy - a.miny + 2 - t) >> 1;
    long long rh = (a.maxy - a.miny + 1 + t) >> 1;

    long long result = lw * lh + rw * rh;

    if (a.minx < m - a.miny) result -= getOutGridCount(a.minx, a.miny, m - a.miny - a.minx, m); //0:m ~ m:0
    if (a.maxx - m > a.miny) result -= getOutGridCount(a.maxx, a.miny, a.maxx - m - a.miny, m); //0:m ~ n:m+n
    if (a.minx < a.maxy - m) result -= getOutGridCount(a.minx, a.maxy, a.maxy - m - a.minx, m); //0:m ~ n:m+n
    if (a.maxx - n > n + m - a.maxy) result -= getOutGridCount(a.maxx, a.maxy, a.maxx - n - (n + m - a.maxy), m); //n:m+n ~ n+m:n
    return result;
}

class SegTree {
    struct X {
        int val;
        int y1;
        int y2;
        int count;

        bool operator <(const X& other) const {
            //시작을 우선시해야 중복점을 제거할 수 있음
            long long o1 = ((long long)val << 2) - count;
            long long o2 = ((long long)other.val << 2) - other.count;
            return o1 < o2;
        }
    };

    struct Node {
        int count;
        int link;
        int prevlink;
        int fill;
        int prevfill;
    };

    X* _x;
    int* _y;
    Node* _node;
    int _xcount;
    int _ycount;
    int _n;
    int _m;

public:
    SegTree(int capacity, int n, int m) :
        _x((X*)calloc(capacity * 2, sizeof(X))),
        _y((int*)calloc(capacity * 2, sizeof(int))),
        _node(NULL),
        _xcount(0),
        _ycount(0),
        _n(n),
        _m(m)
    { }

    ~SegTree() {
        free(_x);
        free(_y);
        if (_node) free(_node);
    }

private:
    void addx(int val, int y1, int y2, int count) {
        X& x = _x[_xcount++];
        x.val = val;
        x.y1 = y1;
        x.y2 = y2;
        x.count = count;
    }

    void addy(int y) {
        _y[_ycount++] = y;
    }

public:
    void clear() {
        _xcount = 0;
        _ycount = 0;
    }

    void add(const Area& a) {
        addx(a.minx, a.miny, a.maxy, 1);
        addx(a.maxx, a.miny, a.maxy, -1);
        addy(a.miny);
        addy(a.maxy);
    }

private:
    void shift(int start, int end, int k) {
        Node& node = _node[k];
        node.prevfill = node.fill;
        node.prevlink = node.link;
        if (node.fill && node.fill < 4) {
            int mid = (start + end) >> 1;
            if (node.fill & 1) shift(start, mid, k << 1);
            if (node.fill & 2) shift(mid + 1, end, k << 1 | 1);
        }
    }

    void update(int y1, int y2, int start, int end, int k, int val) {
        Node& node = _node[k];

        int k1 = k << 1;
        int k2 = k1 | 1;

        if (y1 <= _y[start] && _y[end] <= y2) {
            node.count += val;
            if (_y[end] < y2) node.link += val;
            if (node.count == 0 && start < end) {
                int mid = (start + end) >> 1;
                shift(start, mid, k1);
                shift(mid + 1, end, k2);
            }
        } else if (start < end) {
            int mid = (start + end) >> 1;
            if (y1 <= _y[mid]) update(y1, y2, start, mid, k1, val);
            if (y2 > _y[mid]) update(y1, y2, mid + 1, end, k2, val);
        }

        node.fill = node.count ? 4 : 0;
        if (start < end) {
            if (_node[k1].fill) node.fill |= 1;
            if (_node[k2].fill) node.fill |= 2;
        }
    }

    bool prevlinked(int start, int end, int k) const {
        Node& node = _node[k];
        if (node.prevlink) return true;
        if (node.prevfill & 2) {
            start = ((start + end) >> 1) + 1;
            k = k << 1 | 1;
            return (node.fill & 4) ? linked(start, end, k) : prevlinked(start, end, k);
        }
        return false;
    }

    bool linked(int start, int end, int k) const {
        Node& node = _node[k];
        if (node.link) return true;
        if (node.fill & 2) {
            start = ((start + end) >> 1) + 1;
            k = k << 1 | 1;
            return linked(start, end, k);
        }
        return false;
    }

    long long prevsum(int start, int end, int k, int x, bool prev) const {
        Node& node = _node[k];

        if (node.fill & 4) prev = false;

        int fill = prev ? node.prevfill : node.fill;

        if (fill & 4) {
            int y1 = _y[start];
            int y2 = end < _ycount - 1 && prevlinked(start, end, k) ? _y[end + 1] - 1 : _y[end];
            return getGridCount(Area(x, y1, x, y2), _n, _m);
        }
        else if (fill & 3) {
            long long result = 0;

            int mid = (start + end) >> 1;
            if (fill & 1) result += prevsum(start, mid, k << 1, x, prev);
            if (fill & 2) result += prevsum(mid + 1, end, k << 1 | 1, x, prev);

            return result;
        }
        return 0;
    }

    long long sum(int start, int end, int k, int x1, int x2, int prevfill) {
        Node& node = _node[k];

        if (prevfill == 0 && (node.prevfill & 4)) prevfill = 1;

        long long result = 0;

        if (node.fill & 4) {
            bool linked_ = end < _ycount - 1 && linked(start, end, k);

            int y1, y2;

            if (prevfill == 1) {
                if (linked_ && !prevlinked(start, end, k)) {
                    y1 = _y[end] + 1;
                    y2 = _y[end + 1] - 1;
                    if (y1 <= y2) {
                        result += getGridCount(Area(x1, y1, x1, y2), _n, _m);
                    }
                }
                if (x1 == x2) goto exit;
                x1++;
            }

            y1 = _y[start];
            y2 = linked_ ? _y[end + 1] - 1 : _y[end];
            result += getGridCount(Area(x1, y1, x2, y2), _n, _m);
            if (prevfill == 0 && (node.prevfill & 3)) {
                int mid = (start + end) >> 1;
                if (node.prevfill & 1) result -= prevsum(start, mid, k << 1, x1, true);
                if (node.prevfill & 2) result -= prevsum(mid + 1, end, k << 1 | 1, x1, true);
            }
        }
        else if (node.fill & 3) {
            int mid = (start + end) >> 1;
            if (node.fill & 1) result += sum(start, mid, k << 1, x1, x2, (node.prevfill & 1) ? prevfill : -1);
            if (node.fill & 2) result += sum(mid + 1, end, k << 1 | 1, x1, x2, (node.prevfill & 2) ? prevfill : -1);
        }

    exit:

        node.prevfill = node.fill;
        node.prevlink = node.link;

        return result;
    }

public:
    long long sum() {
        if (!_ycount) return 0;

        sort(_y, _y + _ycount);
        int* pyend = unique(_y, _y + _ycount);
        _ycount = pyend - _y;

        sort(_x, _x + _xcount);

        int nodeCapacity = 1;
        int nodeCount = 1;
        while (nodeCount < _ycount) {
            nodeCount <<= 1;
            nodeCapacity += nodeCount;
        }
        if (nodeCount == _ycount) nodeCapacity++;

        _node = (Node*)calloc(nodeCapacity, sizeof(Node));

        long long result = 0;

        int yend = _ycount - 1;

        for (int i = 0; i < _xcount; i++) {
            const X& x = _x[i];

            if (i > 0) {
                result += sum(0, yend, 1, _x[i - 1].val, x.val, 0);
            }
            update(x.y1, x.y2, 0, yend, 1, x.count);
        }

        free(_node);
        _node = NULL;

        return result;
    }
};

struct Path {
    int x;
    int y;
    int d;
};

static long long debug1(int n, int m, const Path* path, int count) {
    bool* flag = (bool*)calloc((n + 1) * (m + 1), 1);

    for (int i = 0; i < count; i++) {
        const Path& p = path[i];
        int minx = max(p.x - p.d, 0);
        int maxx = min(p.x + p.d, n);
        int miny = max(p.y - p.d, 0);
        int maxy = min(p.y + p.d, m);
        for (int y = miny; y <= maxy; y++) {
            for (int x = minx; x <= maxx; x++) {
                int idx = y * (n + 1) + x;
                if (!flag[idx] && abs(x - p.x) + abs(y - p.y) <= p.d) {
                    flag[idx] = true;
                }
            }
        }
    }
    int k = 0;
    long long answer = 0;
    for (int y = 0; y <= m; y++) {
        for (int x = 0; x <= n; x++) {
            if (flag[k++]) answer++;
        }
    }
    free(flag);

    return answer;
}

static long long debug2(int n, int m, const Path* path, int count) {
    Area a(0, 0, n + m, n + m);

    SegTree tree(count, n, m);

    for (int i = 0; i < count; i++) {
        const Path& p = path[i];
        Area b = clipArea(a, p.x, p.y, p.d, m);
        if (b) tree.add(b);
    }

    long long answer = tree.sum();

    return answer;
}

long long solution(int n, int m, vector<vector<int>> tests) {
    Area a(0, 0, n + m, n + m);
    int failCount = 0;
    for (const vector<int>& test : tests) {
        int x = test[0];
        int y = test[1];
        bool flag = test[3];

        if (flag) {
            int d = test[2];
            a = clipArea(a, x, y, d, m);
            if (!a) return 0;
        }
        else failCount++;
    }

    long long answer = getGridCount(a, n, m);
    if (answer <= 0) return 0;

    if (failCount) {
        SegTree tree(failCount, n, m);

        for (const vector<int>& test : tests) {
            int x = test[0];
            int y = test[1];
            bool flag = test[3];

            if (!flag) {
                int d = test[2];
                Area b = clipArea(a, x, y, d, m);
                if (b) tree.add(b);
            }
        }

        answer -= tree.sum();
    }

    return answer;
}
