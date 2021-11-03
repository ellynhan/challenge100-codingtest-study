#include <iostream>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N,K;
    cin >> N >> K;

    multiset<pair<int,int>> info;
    multiset<int> bags;
    for(int i=0; i<N; i++){
        int m, v;
        cin >> m >> v;
        info.insert({-v,m});
    }
    
    for(int i=0; i<K; i++){
        int w;
        cin >> w;
        bags.insert(w);
    }
    multiset<pair<int,int>>::iterator it;
    multiset<int>::iterator it_bag;

    long long answer = 0;

    for(it=info.begin(); it!=info.end(); it++){
        int currWeight = it->second;
        it_bag = bags.lower_bound(currWeight);
        if(it_bag ==bags.end()){
            continue;
        }else{
            if(*it_bag>=currWeight){
                answer -= it->first;
                bags.erase(it_bag);
            }
        }
        
    }
    cout<<answer;
}

//보석의 무게가 x일 때 가방중에서 x값과 같거나 큰것을 리턴함. 
//만약 보석의 무게가 가방의 무게중 가장 큰 것보다 크다면 end까지가게됨
