//
//  표 편집.cpp
//  main
//
//  Created by wi_seong on 1/31/24.
//

// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Level
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/81303

#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct Node {
    int id;
    int left;
    int right;

    Node(int a, int b, int c): id(a), left(b), right(c) { }
};

string solution(int n, int k, vector<string> cmd) {
    vector<Node> table{};
    for (int i = 0; i <= n; i++)
        table.push_back(Node(i, i - 1, i + 1));

    string answer(n, 'O');

    int cur = k;

    stack<Node> del{};

    for(string c: cmd) {
        char op = c[0];

        if(op == 'U') {
            int x = stoi(c.substr(2));
            while(x--) cur = table[cur].left;
        } else if(op == 'D') {
            int x = stoi(c.substr(2));
            while(x--) cur = table[cur].right;
        } else if(op == 'C') {
            del.push(table[cur]);

            int leftIndex = table[cur].left;
            int rightIndex = table[cur].right;

            if(leftIndex != -1)
                table[leftIndex].right = rightIndex;
            if(rightIndex != n)
                table[rightIndex].left = leftIndex;

            answer[cur] = 'X';

            if(rightIndex == n)
                cur = leftIndex;
            else
                cur = rightIndex;
        } else if(op == 'Z') {
            auto toInsert = del.top();
            del.pop();

            int leftIndex = toInsert.left;
            int rightIndex = toInsert.right;

            if(leftIndex != -1)
                table[leftIndex].right = toInsert.id;
            if(rightIndex != n)
                table[rightIndex].left = toInsert.id;

            answer[toInsert.id] = 'O';
        }
    }

    return answer;
}
