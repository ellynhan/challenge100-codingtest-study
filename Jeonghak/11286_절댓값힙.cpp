#include <iostream>
#include <queue>
using namespace std;
struct cmp{
bool operator()(int a, int b){
    if(abs(a) > abs(b))
        return true;
    else if(abs(a) == abs(b)){
        return a > b;
    }
    else return false;
}};
int N;
priority_queue<int, vector<int>, cmp> pq;

int main()
{
    cin >> N;
    while(N--)
    {
        int a;
        cin >> a;
        if(a != 0)
            pq.push(a);
        else{
            if(pq.empty())
                cout << 0 << '\n';
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
}
