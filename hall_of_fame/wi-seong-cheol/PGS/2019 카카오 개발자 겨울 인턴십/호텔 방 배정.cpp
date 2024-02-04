//
//  호텔 방 배정.cpp
//  main
//
//  Created by wi_seong on 2/1/24.
//

// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Level 4
// Timer: 40m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/64063

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;
class Room {
    public:
    ll _number;
    ll *number;
};
unordered_map<ll, Room*> room;

vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer;
    int n = int(room_number.size());

    for(int i = 0; i < n; i++) {
        if(room[room_number[i]] == NULL) {
            room[room_number[i]] = new Room();
            room[room_number[i]] -> _number = room_number[i];
            room[room_number[i]] -> number = &room[room_number[i]] -> _number;
            answer.push_back(room_number[i]);
        } else {
            ll nextNumber = *(room[room_number[i]] -> number) + 1;

            while(room[nextNumber] != NULL) {
                room[room_number[i]] -> number = room[nextNumber] -> number;
                nextNumber = *(room[nextNumber] -> number) + 1;
            }

            room[nextNumber] = room[room_number[i]];
            *(room[room_number[i]] -> number) = nextNumber;
            answer.push_back(nextNumber);
        }
    }

    return answer;
}
