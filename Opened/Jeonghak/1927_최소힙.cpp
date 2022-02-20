#include <iostream>
#include <queue>
using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int N;
	priority_queue< int, vector<int>, greater<int> > pq;
    cin >> N;

    while(N--){
        int op;
        cin >> op;
        if(op==0){
            if(pq.empty()) cout << 0 << '\n';
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else pq.push(op);
    }
}   
