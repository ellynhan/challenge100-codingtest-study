#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    if(phone_book.size() == 1) return answer;
    
    sort(phone_book.begin(), phone_book.end());
    
    string flag = phone_book[0];
    for(int i = 1; i < phone_book.size(); i++){
        string pb = phone_book[i];
        if(flag.length() <= pb.length() && flag == pb.substr(0, flag.length())) return false;
        else flag = pb;
    }
    
    return answer;
}
