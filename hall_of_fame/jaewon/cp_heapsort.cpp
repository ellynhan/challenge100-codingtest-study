#include <iostream>
using namespace std;
int memo[500001];
void swap(int &a, int & b){
    int t = a;
    a = b;
    b = t;
}

void push_heap(int idx){
    if(idx == 1) return ;
    if(memo[idx] > memo[idx/2]){
        swap(memo[idx],memo[idx/2]);    }
    push_heap(idx/2);
}

void pop_heap(int & last){
    swap(memo[1], memo[last--]);
    for (int i=2; i<=last; i*=2){
        if( i<last && memo[i+1] > memo[i])i++;
        if(memo[i]>memo[i/2]) swap(memo[i],memo[i/2]);
        else break;
    }
}



int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> memo[i];
        push_heap(i);
    }
    for(int i=1; i<=n; i++){
        cout<<memo[i]<<" ";
    }
    cout<<endl;
    int last = n;
    
    for(int i=n; i>0; i--){
        pop_heap(last);
    }

    for(int i=1; i<=n; i++){
        cout<<memo[i]<<" ";
    }
}

/* //with stl//
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int d[500001];

void push_heap(int idx){
    if(idx == 1) return ;
    if(d[idx] > d[idx/2]){
        int tmp = d[idx];
        d[idx] = d[idx/2];
        d[idx/2] = tmp;
    }
    push_heap(idx/2);
}

int main(){
    int n;
    cin >> n;
    priority_queue<int> pq;
    stack<int> s;
    for(int i=1; i<=n; i++){
        cin >> d[i];
        pq.push(d[i]);
        push_heap(i);
    }
    for(int i=1; i<=n; i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;
    while(!pq.empty()){
        s.push(pq.top());
        pq.pop();
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
*/