#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> split(string input, char del){
    vector<string> answer;
    stringstream ss(input);
    string tmp;
    
    while(getline(ss, tmp, del))
        answer.push_back(tmp);
    
    return answer;
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    unordered_map<string, unordered_map<string, int>> um; // {보낸 사람, {받은사람, 개수}};
    unordered_map<string, int> count; // 선물지수(준 선물 - 받은 선물)
    unordered_map<string, int> next; // 다음달에 받을 선물 개수
    
    for(int i = 0; i < friends.size(); i++){
        count.insert({friends[i], 0});
        next.insert({friends[i], 0});
        unordered_map<string, int> gifts;
        for(int j = 0; j < friends.size(); j++){
            if(friends[i] == friends[j]) continue;
            gifts.insert({friends[j], 0});
        }
        um.insert({friends[i], gifts});
    }

    for(int i = 0; i < gifts.size(); i++){
        vector<string> ss = split(gifts[i], ' ');
        string from = ss[0];
        string to = ss[1];
        
        // 선물 리스트 갱신
        um[from][to]++;
        
        // 선물 지수 갱신
        count[from]++;
        count[to]--;
    }
    
    // 이전달에 선물 많이 준 쪽이 다음에 받을 예정
    for(int i = 0; i < friends.size(); i++){
        for(int j = i; j < friends.size(); j++){
            if(friends[i] == friends[j]) continue;
            string A = friends[i];
            string B = friends[j];
            
            int AtoB = um[A][B];
            int BtoA = um[B][A];
            
            if(AtoB < BtoA){
                next[B]++;
            }
            else if(AtoB > BtoA){
                next[A]++;
            }
            else{ // 기록이 없다면 or 같은 수를 주고받았다면 => 선물지수 작은애가 큰애한테 선물줌
                int cntA = count[A];
                int cntB = count[B];
                if(cntA < cntB) next[B]++;
                else if(cntA > cntB) next[A]++;
                else{}; // 안줌
            }
        }
    }
    
    for(auto it : next){
        answer = answer < it.second ? it.second : answer;
    }
    
    
    return answer;
}
