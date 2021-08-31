#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

const int cal[5] = {781,156,31,6,1};
unordered_map<char,int> vowel = {
    {'A' , 1},
    {'E' , 2},
    {'I' , 3},
    {'O' , 4},
    {'U' , 5},
};
int solution(string word) {
    int answer = 0;
    for(int i = 0; i< word.length(); i++)
        answer += (vowel[word[i]] - 1) * cal[i] + 1;
    return answer;
}