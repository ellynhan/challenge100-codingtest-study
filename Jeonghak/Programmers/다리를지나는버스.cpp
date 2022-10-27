#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    deque<int> bridge(bridge_length);
    int passed_trucks = 0;
    int weight_sum = 0;
    int truck_number = 0;
    int truck_weight = 0;
    while(true){
        if(passed_trucks == truck_weights.size())
            break;

        if(bridge.front() != 0)
            passed_trucks++;

        weight_sum -= bridge.front();
        bridge.pop_front();
        answer++;

        truck_weight = truck_weights[truck_number];
        
        if(weight_sum + truck_weight <= weight){
            weight_sum += truck_weight;
            truck_number++;
            bridge.push_back(truck_weight);
        } else {
            bridge.push_back(0);
        }
    }
    return answer;
}