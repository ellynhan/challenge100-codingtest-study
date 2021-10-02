#include <iostream>
#include <vector>
using namespace std;

int difs[13]={0};
int correct[13]={0};

void checkMinus(vector<int>& v){
    for(int i=0; i<4; i++){
        if(correct[v[i]]==1)continue;
        if(difs[v[i]]<=0){
            difs[v[i]]=-1;
        }else{
            correct[v[i]]=1;
        }
        
    }
}    

void checkPlus(vector<int>& v){
    for(int i=0; i<4; i++){
        if(correct[v[i]]==1)continue;
        if(difs[v[i]]>=0){
            difs[v[i]]=1;   
        }else{
            correct[v[i]]=1;
        }
    }
}

void checkOthers(vector<int>& a, vector<int>&b){
    int entire[13]={0};
    for(int i=0; i<4; i++){
        entire[a[i]]=1;
        entire[b[i]]=1;
    }
    for(int i=1; i<=12; i++){
        if(entire[i]==1)continue;
        correct[i]=1;
    }
}

void checkCorrect(vector<int>&a, vector<int>&b){
    for(int i=0; i<4; i++){
        correct[a[i]]=1;
        correct[b[i]]=1;
    }
}


int main(){
    for(int i=0; i<3; i++){
        vector<int> a(4,0),b(4,0);
        int dif;
        char cmp;
        for(int j=0; j<4; j++){
            cin >> a[j];
        }
        cin >> cmp;
        for(int j=0; j<4; j++){
            cin >> b[j];
        }
        if(cmp=='='){
            checkCorrect(a,b);
        }else if(cmp=='<'){
            checkOthers(a,b);
            checkMinus(a);
            checkPlus(b);
        }else{
            checkOthers(a,b);
            checkMinus(b);
            checkPlus(a);
        }
    }
    int cnt = 0;
    int wrong_idx = 0;
    for(int i=1; i<=12; i++){
        if(correct[i]!=1){
            cnt++;
            wrong_idx=i;
        }    
    }
    if(cnt==1){
        cout<<wrong_idx;
        if(difs[wrong_idx]>0){
            cout<<'+';
        }else{
            cout<<'-';
        }
    }else if(cnt>1){
        cout<<"indefinite";
    }else{
        cout<<"impossible";
    }
}
