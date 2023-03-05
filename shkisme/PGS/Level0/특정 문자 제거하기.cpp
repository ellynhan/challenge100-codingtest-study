#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    char l[1];
    letter.copy(l, letter.length()+1);

    for (char m : my_string){
        if (m != l[0]){
            answer += m;
        }
    }

    return answer;
}
