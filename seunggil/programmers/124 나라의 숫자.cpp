#include <string>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<int> toTernary(int num){
    string datas = "";

    while(num){
        datas = to_string(num % 3) + datas;
        num = num/3;
    }
    vector<int> result;
    result.reserve(datas.length());
    
    for(char iter : datas)
        result.push_back(iter-'0');

    return result;
}
string solution(int n) {
    string answer = "";
	
    vector<int> ternary = toTernary(n);
    for(int i = ternary.size()-1; i >= 0; i--){
        if(i != 0 && ternary[i] <= 0){
            ternary[i] = 3 + ternary[i];
            ternary[i-1]--;
        }
        switch(ternary[i]){
            case 0:
                break;
            case 1:
                answer = "1" + answer;
                break;
            case 2:
                answer = "2" + answer;
                break;
            case 3:
                answer = "4" + answer;
                break;
        }
    }
	
	return answer;
}