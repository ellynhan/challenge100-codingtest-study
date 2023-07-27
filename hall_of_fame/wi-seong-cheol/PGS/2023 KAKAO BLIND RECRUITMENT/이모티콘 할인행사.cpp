//
//  이모티콘 할인행사.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/27.
//

// 시간복잡도: O(2 ^ n * (n * m))
// 최악시간: 89,600
// 난이도: Level 2
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/150368

#include <string>
#include <vector>
#include <iostream>

using namespace std;
int n, m;
int mx_user, mx_sales;
int sales[8];
bool isused[8];

void func(int k, vector<vector<int>>& users, vector<int>& emoticons) {
    if(k == m) {
        int user = 0;
        int total = 0;
        
        for(int i = 0; i < n; i++) {
            int price = 0;
            for(int j = 0; j < m; j++) {
                if(sales[j] < users[i][0]) continue;
                price += (emoticons[j] * (100 - sales[j])) / 100;
            }
            if(price >= users[i][1]) user++;
            else total += price;
        }
        if(mx_user < user) {
            mx_user = user;
            mx_sales = total;
        } else if(mx_user == user) {
            mx_sales = max(mx_sales, total);
        }
            
        return;
    }
    
    for(int i = k; i < m; i++) {
        for(int j = 1; j <= 4; j++) {
            if(!isused[i]) {
                isused[i] = true;
                sales[i] = j * 10;
                func(k + 1, users, emoticons);
                isused[i] = false;
            }
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    n = users.size();
    m = emoticons.size();
    
    func(0, users, emoticons);
    answer.push_back(mx_user);
    answer.push_back(mx_sales);
    
    return answer;
}
