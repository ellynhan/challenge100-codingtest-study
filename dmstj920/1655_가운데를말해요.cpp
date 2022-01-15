#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num, mid, temp;
    cin >> num;

    vector<int> res;
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;


    for(int i=0; i<num; i++){
        cin >> mid;

        if(maxpq.size() - minpq.size() == 1){
            minpq.push(mid);
        }

        else{
            maxpq.push(mid);
        }

        if(!minpq.empty() && minpq.top() < maxpq.top()){
            temp = minpq.top();
            minpq.pop();
            minpq.push(maxpq.top());
            maxpq.pop();
            maxpq.push(temp);
        }

       cout << maxpq.top() << '\n';

    }

    return 0;
}
