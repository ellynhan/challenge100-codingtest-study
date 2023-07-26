#include <stdio.h>

typedef unsigned int UI;
const int MOD = 1 << 24;
const int MASK = MOD - 1;
const int LM = 4001;
int N, A[LM], B[LM], C[LM], D[LM];
long long ans = 0;
int bcnt;
struct Node{
    int key, cnt;
    Node * next;
    Node* alloc(int nkey, Node* np){
        key = nkey, cnt = 1, next = np;
        return this;
    }
}buf[LM*LM], *htab[MOD];

void input(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d%d%d%d", A+i, B+i, C+i, D+i);
    }
}

UI hashF(int num){
    return num & MASK; //num % MOD
}

Node* probing(int hidx, int key){
    Node* p = htab[hidx];
    for(; p; p=p->next){
        if(p->key == key)return p;
    }
    return NULL;
}

int main(){
    input();
    int i, j;
    //A,B process
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            int key = A[i] + B[j];
            int hidx = hashF(key); //키 값을 보내면 인덱스값을 받아옴
            Node *p = probing(hidx, key); 
            if(p)p->cnt++;
            else{
                htab[hidx] = buf[bcnt++].alloc(key, htab[hidx]);
            } 
        }
    }
    
    //C,D process
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            int key = -(C[i] +D[j]);
            int hidx = hashF(key);
            Node* p = probing(hidx, key);
            if(p) ans += p->cnt;
        }
    }

    printf("%lld\n", ans);
    return 0;
}