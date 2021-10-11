#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int parent[100];
int childNum[100];

int findParent(int a) {
    if(a == parent[a]) {
        return a;
    }
    
    return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    
    if(a != b) {
        if(childNum[a] > childNum[b]) {
            parent[b] = a;
            
            childNum[a] += childNum[b];
        }
        else {
            parent[a] = b;
            
            childNum[b] += childNum[a];
        }
    }
}

int isUnion(int a, int b) {
    if(findParent(a) == findParent(b)) {
        return 1;
    }
    else {
        return 0;
    }
}


bool compare(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int sizeEdge = costs.size();
    
    // making parent to default
    for(int i = 0; i < 100; i++) {
        parent[i] = i;
    }
    
    
    // sorting
    sort(costs.begin(), costs.end(), compare);
    
    /*
    for(int i = 0; i < sizeEdge; i++) {
        cout << costs[i][2] << " ";
    }
    */
    
    for(int i = 0; i < sizeEdge; i++) {
        if(!isUnion(costs[i][0], costs[i][1])) {
            answer += costs[i][2];
            unionParent(costs[i][0], costs[i][1]);
        }
    }
    
    return answer;
}
