/* 
    Trie 연습
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int SIZE = 1000;

struct Node{
    string name;
    //Node* food[SIZE]; //근데 이렇게하면 사전순으로 출력이 불가함. 그럼 벡터나 큐로 넣어야하나? 근데 큐는 중간에 들어가기가 어려워. 배열을 이용한 힙을 만들면 몰라도..
    vector<Node*> foods; //근데 백터로하면 어떻게 기억해 그 인덱스가 어딘지 
    map<string, int> nameindex; //이렇게 인덱스로 처리해야하나?, 혹시 먹이 창고가 같은 이름으로 여러개가 같은 부모아래 있다면? 그럼 multiple 써야함 (쉽지않네;)
    Node(string n){
        name = n;
    }
    Node(){}
};

bool comp(string s1, string s2){
    return s1 < s2;
}

bool comp2(Node* n1, Node* n2){
    return n1->name < n2->name;
}

void sorting(Node* parent){
    if(parent == NULL) return ;
    sort(parent->foods.begin(), parent->foods.end(),comp2);
    for(int i=0; i<parent->foods.size(); i++){
        sorting(parent->foods[i]);
    }
}

void printing(Node* parent, int cnt){
    if(parent == NULL) return ;
    for(int i=0; i<parent->foods.size(); i++){
        for(int j=0; j<cnt; j++){
            cout<<"--";
        }
        cout<<parent->foods[i]->name<<endl;
        printing(parent->foods[i], cnt+1);
    }
}

int main(){
    int N;
    Node* root = new Node();
    cin >> N;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        Node* curr = root;
        for(int j=0; j<num; j++){
            //받은 이름이 없으면 추가, 있으면 냅둠
            //그러고는 다음 노드로 넘어감. 
            string name;
            cin >> name;
            if(curr->nameindex.count(name)==0){
                curr->foods.push_back(new Node(name));
                curr->nameindex[name] = curr->foods.size()-1;
            }
            int idx = curr->nameindex[name];
            curr = curr->foods[idx];
        }
    }
    sorting(root);
    printing(root, 0);
}