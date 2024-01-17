#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<string> ss;
bool splitBab(string bab, int pos){
    string preBab{};
    while(pos < bab.length()){
        char c = bab[pos];
        string str;
        if(c == 'a'){
            str.append(bab, pos, 3);
            auto it = ss.find(str);
            if(it == ss.end()){
                return false;
            }
            if(preBab == str){
                return false;
            }
            preBab = str;
            pos += 3;
        }
        else if(c == 'w'){
            str.append(bab, pos, 3);
            auto it = ss.find(str);
            if(it == ss.end()){
                return false;
            }
            if(preBab == str){
                return false;
            }
            preBab = str;
            pos += 3;
        }
        else if(c == 'y'){
            str.append(bab, pos, 2);
            auto it = ss.find(str);
            if(it == ss.end()){
                return false;
            }
            if(preBab == str){
                return false;
            }
            preBab = str;
            pos += 2;
        }
        else if(c == 'm'){
            str.append(bab, pos, 2);
            auto it = ss.find(str);
            if(it == ss.end()){
                return false;
            }
            if(preBab == str){
                return false;
            }
            preBab = str;
            pos += 2;
        }
        else {
            return false;
        }
    }
    return true;
}

int solution(vector<string> babbling) {
    int answer = 0;
    ss.insert("aya");
    ss.insert("ye");
    ss.insert("woo");
    ss.insert("ma");
    
    for(int i = 0; i < babbling.size(); i++){
        string bab = babbling[i];
        if(bab.length() < 2) continue;
        bool isIn = splitBab(bab, 0);
        if(isIn){
            answer++;
        }
    }
    return answer;
}
