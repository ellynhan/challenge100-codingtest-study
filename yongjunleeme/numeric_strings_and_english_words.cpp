#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    for(int i = 0; i < 10; i++){
        while(1){
            auto it = s.find(arr[i]);
            if(it == string::npos) break;
            s.replace(it, arr[i].size(), to_string(i));
        }
    }
    return stoi(s);
}
