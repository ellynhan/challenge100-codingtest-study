//
//  행렬의 곱셈.cpp
//  main
//
//  Created by wi_seong on 2/10/24.
//

// 시간복잡도: O(n ^ 3)
// 최악시간: 1,000,000
// 난이도: Level 2
// Timer: 20m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12949

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int n = int(arr1.size());
    int m = int(arr2[0].size());
    vector<vector<int>> answer(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < int(arr2.size()); k++)
                answer[i][j] += arr1[i][k] * arr2[k][j];
        }
    }

    return answer;
}
