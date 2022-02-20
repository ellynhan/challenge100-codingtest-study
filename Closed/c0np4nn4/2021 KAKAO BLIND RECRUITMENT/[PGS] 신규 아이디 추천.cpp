#include <string>
#include <vector>
#include <algorithm>


using namespace std;

string solution(string new_id) {
    string answer = "";
    
    string id = "";
    
    // step 1.
    for (int i = 0; i < new_id.length(); i++) {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z') {
            new_id[i] = new_id[i] - 'A' + 'a';
        }
    }
    
    // step 2.
    for (int i = 0; i < new_id.length(); i++) {
        if (  new_id[i] == '-'
           || new_id[i] == '.'
           || new_id[i] == '_'
           || (new_id[i] >= 'a' && new_id[i] <= 'z')
           || (new_id[i] >= '0' && new_id[i] <= '9') ) {
            id += new_id[i];
        }
        else { continue; }
    }
    
    // step 3.
    for (int i = 0; i < id.length(); i++) {
        if (id[i] == '.') {
            int index = i + 1;
            while (id[index] == '.') {
                id.erase(id.begin() + index);
            }
        }
    }
    
    // step 4.
    if (id.front() == '.') id.erase(id.begin());
    if (id.back() == '.') id.pop_back();
    
    // step 5.
    if (id.empty()) id = "a";
    
    // step 6.
    if (id.length() >= 16) {
        id = id.substr(0, 15);
    }
    
    if (id.back() == '.') id.pop_back();
    
    // step 7.
    while (id.length() <= 2) {
        id += id.back();
    }
    
    
    
    answer = id;
    return answer;
}
