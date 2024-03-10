//
//  네오의 목걸이.cpp
//  main
//
//  Created by wi_seong on 2/19/24.
//

// 시간복잡도: O(nlgon)
// 최악시간: 1,200,000
// 난이도: Level 5
// Timer: 2h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/1842

#include <map>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

using namespace std;

const long long mod = 1e9 + 7;
const long long inf = mod * mod;
const int NSIZE = 200200;

// Segment Tree 구현
class segtree {
public:
    int n;
    vector<long long> tree;

    // Segment Tree 초기화
    void clear() {
        tree.clear();
    }

    // 최대 트리 크기 계산
    int maxtree(int s, int e, int now) {
        if (s == e) return now;
        return max(maxtree(s, (s + e) / 2, now * 2),
                   maxtree((s + e) / 2 + 1, e, now * 2 + 1));
    }

    // Segment Tree 생성
    void init(int _n) {
        n = _n;
        tree.resize(maxtree(0, n, 1) + 10);
        fill(tree.begin(), tree.end(), 0);
    }

    // 값 업데이트
    void upd(int p, long long c) {
        update(0, n, 1, p, c);
    }

    // 재귀적으로 값 업데이트
    long long update(int s, int e, int now, int p, long long c) {
        if (p < s || e < p) return tree[now];
        if (s == e) {
            return tree[now] = (tree[now] + c) % mod;
        }
        return tree[now] = (update(s, (s + e) / 2, now * 2, p, c) +
                            update((s + e) / 2 + 1, e, now * 2 + 1, p, c)) % mod;
    }

    // 쿼리 처리
    long long qry(int l, int r) {
        return query(0, n, 1, l, r) % mod;
    }

    // 재귀적으로 쿼리 결과 반환
    long long query(int s, int e, int now, int l, int r) {
        if (r < l) return 0;
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return tree[now] % mod;
        return (query(s, (s + e) / 2, now * 2, l, r) +
                query((s + e) / 2 + 1, e, now * 2 + 1, l, r)) % mod;
    }
};

// 문제에 필요한 변수 선언
int dp[NSIZE]; // dp[i]: i번째 점이 오른쪽 아래 점으로 끝날 때의 경우의 수
int dp2[NSIZE]; // dp2[i]: i번째 점이 왼쪽 위 점으로 시작점일 때의 경우의 수
vector<long long> lineVal; // 각 점들의 x - y 값
vector<int> linelu[NSIZE], linerb[NSIZE]; // x-y 값에 따른 점들의 인덱스 벡터
vector<long long> luSum[NSIZE], luSum2[NSIZE], rbSum[NSIZE]; // 누적합 배열
segtree rbSum2[NSIZE]; // 오른쪽 아래 점에 대한 Segment Tree 배열
bool visit[NSIZE];
int lupos[NSIZE][2], rbpos[NSIZE][2]; // 점들의 위치 저장

// 초기화 함수
void init(int n, vector<vector<int>>& point) {
    // dp 배열과 dp2 배열 초기화
    memset(dp, 0, sizeof(dp));
    memset(dp2, 0, sizeof(dp2));
    lineVal.clear(); // lineVal 벡터 초기화

    // 점들을 x, y, 추가 차원에 따라 정렬
    sort(point.begin(), point.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] != b[0]) return a[0] < b[0]; // x 좌표에 따라 정렬
        if (a[1] != b[1]) return a[1] > b[1]; // y 좌표가 같으면 y 좌표에 따라 내림차순 정렬
        return a[2] > b[2]; // 그 외 경우 추가 차원에 따라 내림차순 정렬
    });

    // 각 배열 초기화
    for (int i = 0; i < NSIZE; ++i) {
        linelu[i].clear();
        linerb[i].clear();
        luSum2[i].clear();
        luSum[i].clear();
        rbSum[i].clear();
        rbSum2[i].clear();
    }

    // lineVal 벡터를 채우고, 정렬 및 중복 제거
    for (int i = 0; i < n; ++i) {
        lineVal.push_back(0LL + point[i][0] - point[i][1]);
        lineVal.push_back(0LL + point[i][0] - point[i][1] - point[i][2]);
    }
    sort(lineVal.begin(), lineVal.end());
    lineVal.erase(unique(lineVal.begin(), lineVal.end()), lineVal.end());

    // 각 점을 해당하는 벡터에 할당
    for (int i = 0; i < n; ++i) {
        long long target = point[i][0] - point[i][1];
        int idx = lower_bound(lineVal.begin(), lineVal.end(), target) - lineVal.begin();
        assert(lineVal[idx] == target);
        linelu[idx].push_back(i);
        lupos[i][0] = idx;
        lupos[i][1] = linelu[idx].size() - 1;

        target = point[i][0] - point[i][1] - point[i][2];
        idx = lower_bound(lineVal.begin(), lineVal.end(), target) - lineVal.begin();
        assert(lineVal[idx] == target);
        linerb[idx].push_back(i);
        rbpos[i][0] = idx;
        rbpos[i][1] = linerb[idx].size() - 1;
    }

    // 각 rbSum2[i]를 초기화
    for (int i = 0; i < NSIZE; ++i) {
        rbSum2[i].init(linerb[i].size());
    }

    // dp와 luSum에 대한 초기값 설정
    assert(linelu[lupos[0][0]].size() == 1);
    dp[0] = 1;
    luSum[lupos[0][0]].push_back(1);

    // lineVal 배열을 순회하며 각 점에 대한 계산을 수행
    for (int i = 0; i < lineVal.size(); i++) {
        for (int j = 0; j < linelu[i].size(); j++) {
            int now = linelu[i][j];
            long long a = point[now][0], b = point[now][1], k = point[now][2];
            // 해당 점에 대응되는 lineVal 값 찾기
            int p = lower_bound(lineVal.begin(), lineVal.end(), a - b - k) - lineVal.begin();
            assert(p == rbpos[now][0]);

            // k가 1이거나 linelu[p]가 비어있으면 계속 진행
            if (linelu[p].empty() || k == 1) continue;

            // l과 r을 찾기 위한 범위 계산
            vector<int> temp = { (int)(a - (k - 1)), (int)(b + 1), 0 };
            int l = lower_bound(linelu[p].begin(), linelu[p].end(), temp,
                                [&](int tt, vector<int> ss) { return point[tt] < ss; }) - linelu[p].begin();
            temp = { (int)(a - 1), (int)(b + k - 1), 1987654321 };
            int r = upper_bound(linelu[p].begin(), linelu[p].end(), temp,
                                [&](vector<int> ss, int tt) { return ss < point[tt]; }) - linelu[p].begin();
            if (l >= r) continue; // 유효한 범위가 없으면 스킵

            // dp[now] 업데이트
            dp[now] = l >= 1 ? luSum[p][r - 1] - luSum[p][l - 1] : luSum[p][r - 1];
            dp[now] = (dp[now] + mod) % mod;
        }

        // luSum[i] 업데이트
        long long s = 0;
        for (int j = 0; j < linelu[i].size(); j++) {
            s += dp[linelu[i][j]];
            s %= mod;
            luSum[i].push_back(s);
        }
    }

    // rbSum 배열을 업데이트하는 로직
    for (int i = 0; i < lineVal.size(); i++) {
        long long s = 0;
        for (int j = 0; j < linerb[i].size(); j++) {
            s += dp[linerb[i][j]];
            s %= mod;
            rbSum[i].push_back(s);
        }
    }

    assert(linelu[lupos[n - 1][0]].size() == 1);
    dp2[n - 1] = 1;
    luSum2[lupos[n - 1][0]].push_back(1);
    // lineVal에 대해 역순으로 순회하면서 각 점에 대한 dp2 값을 계산
    for (int i = lineVal.size() - 1; i >= 0; i--) {
        for (int j = 0; j < linelu[i].size(); j++) {
            int now = linelu[i][j];
            long long a = point[now][0], b = point[now][1], k = point[now][2];
            int p = lupos[now][0];

            // 해당 점에서 시작하는 다른 점들과의 관계를 확인
            if (linerb[p].empty()) continue; // 시작점이 없으면 계속

            // 다음 점을 찾기 위한 조건 설정
            vector<int> temp = { (int)(a + 1), 0, 0 };
            int l = lower_bound(linerb[p].begin(), linerb[p].end(), temp,
                                [&](int tt, vector<int> ss) { return ss > point[tt]; }) - linerb[p].begin();
            int r = upper_bound(linerb[p].begin(), linerb[p].end(), b - 1,
                                [&](int bb, int tt) { return bb < point[tt][1]; }) - linerb[p].begin();

            if (l >= r) continue; // 유효한 범위가 없으면 계속

            // dp2 값 업데이트
            dp2[now] = rbSum2[p].qry(l, r) % mod;
        }

        // linelu[i]의 모든 점에 대해 dp2 값을 누적하여 저장
        long long s = 0;
        for (int j = 0; j < linelu[i].size(); j++) {
            s += dp2[linelu[i][j]];
            s %= mod;
            luSum2[i].push_back(s);
        }

        // rbSum2 업데이트
        for (int j = 0; j < linelu[i].size(); j++) {
            int now = linelu[i][j];
            rbSum2[rbpos[now][0]].upd(rbpos[now][1], dp2[now]);
        }
    }
}

vector<int> solution(int n, vector<vector<int>> point, vector<vector<int>> query) {
    // 점들의 배열 초기화
    assert(point.size() == n);
    init(n, point); // 사전 계산 및 초기화
    vector<int> answer;
    answer.push_back(dp[n - 1]); // 초기 답변에 dp[n-1] 값을 추가

    for (auto& q : query) {
        int type = q[0]; // Query type
        long long a = q[1], b = q[2], k; // Parameters of the query
        long long pre = 0, nxt = 0; // Variables to hold intermediate results

        if (type == 0) { // Type 0 query
            k = q[3];
            // Find the position 'p' in 'lineVal' for a given condition
            int p = lower_bound(lineVal.begin(), lineVal.end(), a - b - k) - lineVal.begin();
            if (k != 1 && p < lineVal.size() && lineVal[p] == a - b - k && !linelu[p].empty()) {
                // Calculate 'pre' based on the positions 'l' and 'r' within 'linelu[p]'
                vector<int> temp = {static_cast<int>(a - k + 1), static_cast<int>(b + 1), 0};
                int l = lower_bound(linelu[p].begin(), linelu[p].end(), temp, [&](int tt, vector<int> ss) {
                    return point[tt] < ss;
                }) - linelu[p].begin();
                temp = {static_cast<int>(a - 1), static_cast<int>(b + k - 1), 1987654321};
                int r = upper_bound(linelu[p].begin(), linelu[p].end(), temp, [&](vector<int> ss, int tt) {
                    return ss < point[tt];
                }) - linelu[p].begin();
                pre = l >= 1 ? luSum[p][r - 1] - luSum[p][l - 1] : luSum[p][r - 1];
            }
            // Repeat similar process for 'nxt' using 'linerb'
            p = lower_bound(lineVal.begin(), lineVal.end(), a - b) - lineVal.begin();
            if (p < lineVal.size() && lineVal[p] == a - b && !linerb[p].empty()) {
                vector<int> temp = {static_cast<int>(a + 1), 0, 0};
                int l = lower_bound(linerb[p].begin(), linerb[p].end(), temp, [&](int tt, vector<int> ss) {
                    return point[tt] < ss;
                }) - linerb[p].begin();
                int r = upper_bound(linerb[p].begin(), linerb[p].end(), b - 1, [&](int bb, int tt) {
                    return bb < point[tt][1];
                }) - linerb[p].begin();
                nxt = rbSum2[p].qry(l, r) % mod;
            }
        } else { // Type 1 query (direct access)
            vector<int> temp = {q[1], q[2], 1987654321};
            int pidx = lower_bound(point.begin(), point.end(), temp, [](vector<int> a, vector<int> b) {
                return a[0] != b[0] ? a[0] < b[0] : (a[1] != b[1] ? a[1] > b[1] : a[2] > b[2]);
            }) - point.begin();
            pre = dp[pidx] % mod;
            nxt = dp2[pidx] % mod;
        }

        // Calculate and update the answer based on 'pre' and 'nxt'
        long long nowans = answer.front();
        pre %= mod;
        nxt %= mod;
        if (type == 0) nowans += pre * nxt;
        else nowans -= pre * nxt;
        while (nowans < 0) nowans += (2 + (-nowans) / mod) * mod;
        nowans %= mod;

        answer.push_back(nowans); // Add the result of the current query to the answer
    }

    return answer; // 최종 답변 반환
}
