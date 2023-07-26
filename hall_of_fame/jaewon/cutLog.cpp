#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

#define ll long long

int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    int n, goal;
    cin >> n >> goal;

    vector<int> trees;
    int maxHeight = 1;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        trees.push_back(tmp);
        if(tmp>maxHeight)maxHeight = tmp;
    }
    sort(trees.rbegin(), trees.rend());
    
    int minHeight = 0;
    int answer = 0;
    while(maxHeight>=minHeight){
        ll total = 0;
        int mid = (maxHeight+minHeight)/2;
        for(int i=0; i<n&&trees[i]>mid; i++){
            total += trees[i]-mid;
            if(total>=goal){
                if(answer<mid){
                    answer = mid;
                }
                minHeight = mid+1;
                break;
            }
        }
        if(total<goal){
            maxHeight = mid-1;
        }
    }
    cout<<answer;
}

