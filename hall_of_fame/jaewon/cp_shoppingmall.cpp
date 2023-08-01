#include <iostream>
#include <queue>
using namespace std;

int N, K;
long long ans;

struct Data{
    int id, tm, cnum;
    bool operator<(const Data& r)const{
        if(tm != r.tm) return tm > r.tm;
        return cnum < r.cnum;
    }
    bool operator>(const Data& r)const{
        if(tm != r.tm) return tm > r.tm;
        return cnum > r.cnum;
    }
};
priority_queue<Data, vector<Data>, greater<Data>> minpq;
priority_queue<Data, vector<Data>, less<Data>> maxpq;

int main(){
    cin >> N >> K;
    int  i, id, num;

    //고객을 먼저 계산대 순으로 배정
    for( i=1; i<=N && i<=K; i++){
        cin >> id >> num;
        minpq.push({id, num, i});
    }

    //고객이 남아 있다면 시간 > 빠른 계산대 순으로 배정
    //계산대를 나온 고객은 maxpq에 추가
    for(; i<=N; i++){
        cin >> id >> num;
        Data ret = minpq.top();
        minpq.pop();
        maxpq.push(ret);
        minpq.push({id,ret.tm+num, ret.cnum});
    }

    while(!minpq.empty()){
        Data ret = minpq.top();
        minpq.pop();
        maxpq.push(ret);
    }

    for(i=1; i<=N; i++){
        Data ret = maxpq.top();
        maxpq.pop();
        ans += (long long)i*ret.id;
    }
    cout<<ans;
}