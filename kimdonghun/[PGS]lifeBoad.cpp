#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int checked[50001];

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end(), greater<>());

    int head = 0;
    int tail = people.size() - 1;

    int boatNum = 0;
    int weightSum = people[head];
    
    
    while(head <= tail) {  
        
        weightSum = people[head] + people[tail];
        
        if(weightSum <= limit) {
            head++;
            tail--;
        } 
        else {
            head++;
        }
        
        boatNum++;
        
    }

    answer = boatNum;
    return answer;
}
