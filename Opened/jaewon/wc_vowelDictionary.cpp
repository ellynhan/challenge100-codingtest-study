#include <string>
#include <vector>
#include <set>
#include <iterator>
using namespace std;
string alpha[5]={"A","E","I","O","U"};
int solution(string word) {
    vector<string> v={"A","E","I","O","U"};
    int len = 4;
    int num = 1;
    int start = 0;
    while(len--){
        num*=5;
        for(int i=start; i<start+num; i++){
            for(int j=0; j<5; j++){
                v.push_back(v[i]+alpha[j]);
            }
        }
        start += num;
    }
    set<string> s;
    set<string>::iterator it;
    for(int i=0; i<v.size(); i++){
        s.insert(v[i]);
    }
    it = s.find(word);
    return distance(s.begin(), it)+1;
}
