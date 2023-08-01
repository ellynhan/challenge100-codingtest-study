#include <string>
#include <vector>
#include <set>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    bool needOne = true;

    priority_queue<int, vector<int>, greater<int>> lowscoville;
    multiset<int> highscoville;

    for(int i : scoville){
        if(i < K){
            lowscoville.push(i);
            if(i > K/2)
                needOne = false;
        }else
            highscoville.insert(i);
    }



    if(true && highscoville.size())
        lowscoville.push(*highscoville.begin());

    int answer = 0;
    while(lowscoville.size() > 1 && lowscoville.top() < K){
        int a = lowscoville.top();
        lowscoville.pop();
        int b = lowscoville.top();
        lowscoville.pop();
        lowscoville.push(a + 2 * b);
        answer++;
    }

    if(lowscoville.top() < K)
        answer = -1;

    return answer;
}