//
//  시험장 나누기.cpp
//  main
//
//  Created by wi_seong on 2/16/24.
//

// 시간복잡도: O(nlogn)
// 최악시간: 90,000
// 난이도: Level 5
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/81305

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Node {
    int val, left, right;
};
const int INF = 1e9 + 7;
int root, divideCount;
bool isDivide;
Node tree[10001];
vector<int> value;

void makeTree(const vector<vector<int>>& links) {
    int n = int(value.size());
    int m = int(links.size());
    vector<bool> isused(n, false);

    for(int i = 0; i < m; i++) {
        tree[i] = {value[i], links[i][0], links[i][1]};
        if(links[i][0] != -1) isused[links[i][0]] = true;
        if(links[i][1] != -1) isused[links[i][1]] = true;
    }
    for(int i = 0; i < n; i++) {
        if(!isused[i]) {
            root = i;
        }
    }
}

int findCase(int cur, int l, int r, int mid) {
    if(cur + l + r <= mid) return 1;
    if(cur + l > mid && cur + r > mid) return 2;
    if(cur + l > mid) return 3;
    if(cur + r > mid) return 4;
    return 5;
}

int dfs(int cur, int mid) {
    if(cur == -1) return 0;
    if(value[cur] > mid) {
        isDivide = false;
        return -1;
    }

    int lc = dfs(tree[cur].left, mid);
    int rc = dfs(tree[cur].right, mid);
    if(isDivide == false) return 0;

    int c = findCase(value[cur], lc, rc, mid);
    if(c == 1) return value[cur] + lc + rc;
    else if(c == 2) {
        divideCount += 2;
        return value[cur];
    } else if(c == 3) {
        divideCount += 1;
        return value[cur] + rc;
    } else if(c == 4) {
        divideCount += 1;
        return value[cur] + lc;
    } else {
        divideCount += 1;
        return value[cur] + min(lc, rc);
    }
}

bool solve(int k, int mid) {
    divideCount = 0;
    isDivide = true;
    dfs(root, mid);
    return isDivide && divideCount < k;
}

int solution(int k, vector<int> num, vector<vector<int>> links) {
    int answer = INF;
    value = num;
    makeTree(links);

    int st = 1;
    int en = 1e9;
    while(st <= en) {
        int mid = (st + en + 1) / 2;

        if(solve(k, mid)) {
            en = mid - 1;
            answer = min(answer, mid);
        } else {
            st = mid + 1;
        }
    }

    return answer;
}
