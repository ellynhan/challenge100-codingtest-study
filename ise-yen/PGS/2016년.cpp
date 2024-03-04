#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    string week[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    int sum = -1;
    for(int i = 1; i < a; i++){
        if(i == 2) sum += 29;
        else{
            if(i <= 7){
                if(i % 2 == 1) sum += 31;
                else sum += 30;
            }
            else {
                if(i % 2 == 0) sum += 31;
                else sum += 30;
            }

        }
    }
    sum += b;
    sum %= 7;
    answer = week[sum];
    return answer;
}
