//
//  13168.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 14 40000
 Boseong Busan Changwon Cheonan Chuncheon Daegu Daejeon Gwangju Jeonju Jinju Masan Seoul Suncheon Yeosu
 9
 Seoul Jeonju Suncheon Yeosu Suncheon Boseong Jinju Busan Seoul
 23
 KTX Seoul Busan 20000
 KTX Seoul Gwangju 12000
 KTX Gwangju Yeosu 8000
 KTX Seoul Jinju 17000
 ITX-Saemaeul Seoul Cheonan 7000
 ITX-Cheongchun Seoul Chuncheon 3000
 V-Train Chuncheon Daegu 10000
 Subway Seoul Cheonan 2000
 ITX-Saemaeul Cheonan Daejeon 4000
 ITX-Saemaeul Daejeon Daegu 10000
 ITX-Saemaeul Daegu Busan 7000
 Mugunghwa Daejeon Daegu 6000
 Mugunghwa Daejeon Gwangju 5000
 Mugunghwa Gwangju Jeonju 1500
 Mugunghwa Jeonju Suncheon 4000
 Mugunghwa Suncheon Yeosu 1500
 S-Train Busan Changwon 3000
 S-Train Changwon Masan 1000
 S-Train Masan Jinju 2000
 S-Train Jinju Suncheon 2000
 S-Train Suncheon Boseong 1000
 Bus Busan Jinju 1500
 Bus Suncheon Jinju 4000
 [Output]
 Yes
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 1,000,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/13168

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;
const int INF = 0x3f3f3f3f;
int n, m, k, citycnt, nailro_price, cost;
string city, trans, st, en;
map<string, int> nailro_sale;
map<string, int> citys;
vector<int> dest;
int d[2][101][101];

int trans_code(string &str) {
    if(str[0] == 'S' && str[1] == '-') return 1; // S-train: 50% 할인
    else if(str[0] == 'V') return 1; // V-train: 50% 할인
    else if(str[0] == 'I' || str[0] == 'M') return 2; // ITX, 무궁화: 공짜
    return 0; // 가격 변동 없음
}

void input() {
    cin >> n >> nailro_price;
    nailro_price *= 2;
    for(int i = 0; i < n; i++) {
        cin >> city;
        if(citys.find(city) == citys.end())
            citys[city] = citycnt++;
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> city;
        dest.push_back(citys[city]);
    }
    memset(d, 0x3f, sizeof(d));
    for(int i = 0; i < citycnt; i++) {
        d[0][i][i] = 0;
        d[1][i][i] = 0;
    }
    cin >> k;
    while(k--) {
        cin >> trans >> st >> en >> cost;
        cost *= 2;
        int u = citys[st];
        int v = citys[en];
        cost = min(d[0][u][v], cost);
        d[0][u][v] = d[0][v][u] = cost;
        
        int trcode = trans_code(trans);
        if(trcode == 1) cost /= 2;
        else if(trcode == 2) cost = 0;
        
        cost = min(d[1][u][v], cost);
        d[1][u][v] = d[1][v][u] = cost;
    }
}

void floyd() {
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int m = 0; m < 2; m++)
                    d[m][i][j] = min(d[m][i][j], d[m][i][k] + d[m][k][j]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    floyd();
    for(int i = 1; i < dest.size(); i++) {
        int u = dest[i - 1];
        int v = dest[i];
        nailro_price -= d[0][u][v];
        nailro_price += d[1][u][v];
    }

    if(nailro_price < 0) cout << "Yes";
    else cout << "No";
    
    return 0;
}
