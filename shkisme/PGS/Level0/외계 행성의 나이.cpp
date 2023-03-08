#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = "";
    
    string Age = to_string(age);

    for (char a : Age){
        answer += a - '0' + 'a';
    }
    
    return answer;
}
