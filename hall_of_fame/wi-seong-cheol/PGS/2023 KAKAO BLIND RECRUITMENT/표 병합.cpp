//
//  표 병합.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/27.
//

// 시간복잡도: O(α(n) * n)
// 최악시간: 1000
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/150366

#include <string>
#include <vector>
#include <sstream>
#include <tuple>

using namespace std;

struct cell {
    int ptr;
    string value="EMPTY";
};

int find(int x, vector<cell>& table){
    if(table[x].ptr == x) {
        return x;
    } else{
        return table[x].ptr = find(table[x].ptr, table);
    }
}

void merge(int x, int y, vector<cell>& table) {
    x = find(x, table);
    y = find(y, table);
    
    if (table[x].value == "EMPTY" && table[y].value != "EMPTY"){
        table[x].ptr = y;
    }
    else{
        table[y].ptr = x;
    }
}

vector<string> solution(vector<string> commands) {
    int r1, c1, r2, c2;
    string value1, value2;
    vector<string> answer;
    vector<cell> table(50 * 50);
    for(int i = 0; i < 50 * 50; i++){
        table[i].ptr = i;
    }
    
    for(string c: commands) {
        istringstream ss(c);
        string stringBuffer;
        vector<string> v;
        while (getline(ss, stringBuffer, ' ')) {
            v.push_back(stringBuffer);
        }
        if(c[0] == 'U' && c[1] == 'P') {
            if(v.size() == 3) {
                value1 = v[1];
                value2 = v[2];
                for(auto& i: table) {
                    if(i.value == value1)
                        i.value = value2;
                }
            } else {
                r1 = stoi(v[1]) - 1;
                c1 = stoi(v[2]) - 1;
                value1 = v[3];
                int idx = r1 * 50 + c1;
                table[find(idx, table)].value = value1;
            }
        } else if(c[0] == 'U') {
            r1 = stoi(v[1]) - 1;
            c1 = stoi(v[2]) - 1;

            int idx = r1 * 50 + c1;
            int root = find(idx, table);
            value1 = table[root].value;
            vector<int> target;

            for(int i = 0; i < 50 * 50; ++i){
                if (table[find(i, table)].ptr == root){
                    target.push_back(i);
                }
            }

            for(int i: target){
                table[i].value = "EMPTY";
                table[i].ptr = i;
            }
            table[idx].value = value1;
        } else if(c[0] == 'M') {
            r1 = stoi(v[1]) - 1;
            c1 = stoi(v[2]) - 1;
            r2 = stoi(v[3]) - 1;
            c2 = stoi(v[4]) - 1;
            merge(r1 * 50 + c1, r2 * 50 + c2, table);
        } else if(c[0] == 'P') {
            r1 = stoi(v[1]) - 1;
            c1 = stoi(v[2]) - 1;
            string res = table[find(r1 * 50 + c1, table)].value;
            answer.push_back(res);
        }
    }
    
    return answer;
}
