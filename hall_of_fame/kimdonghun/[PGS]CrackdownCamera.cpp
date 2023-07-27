#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    if(a[1] != b[1]) {
        return a[1]  < b[1];
    }
    else {
        return a[0] < b[0];
    }
}


int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), compare);
    
    int lastSpot = -30001;
    
    
    for(int i = 0; i < routes.size(); i++) {
        //out << routes[i][0] << " " << routes[i][1]  << "\n";
        //cout << lastSpot << "\n";
        
        if(routes[i][0] > lastSpot) {
            lastSpot = routes[i][1];
            answer++;
        }
        else if(routes[i][1] < lastSpot) {
            break;
        }
    }
    
    return answer;
}
