/*
전화번호 검색 - Trie
trie, index buffer, loop
*/
#include <stdio.h>

const int LM = 10000;
const int CHILD = 10;

struct Trie{
    struct Node{
        int child[CHILD]; //자식 노드를 가리키는 index 저장
        bool wordFlag;    //현재 노드로 단어가 완성되는가?
        void init(){
            for(int i=0; i<CHILD; ++i){
                child[i] = 0;
            }
            wordFlag = false;
            return ;
        }
    }buf[LM*10];        //10만개 
    int bcnt, root;     //버퍼이기 때문에 bcnt로 동적할당과 같아 보이게 함

    void init(){
        bcnt = root = 0;
        buf[0].init();
    }

    void insert(char* s, int par){
        for(; *s; ++s){
            int idx = *s - '0';
            if(buf[par].child[idx]==0){
                buf[par].child[idx] = ++bcnt, buf[bcnt].init();
            }
            par = buf[par].child[idx];
        }
        buf[par].wordFlag = true;
    }

    bool search(char*s, int par){
        for(; *s && !buf[par].wordFlag;++s){
            int idx = *s - '0';
            if(buf[par].child[idx] ==0)return 1;
            par = buf[par].child[idx];
        }
        return 0;
    }
}trie;  //전역변수로 선언된 객체. 

int main(){
    int tc, N;
    char s[12];
    scanf("%d", &tc);
    while(tc--){
        trie.init();
        scanf("%d", &N);
        int flag = 1;   //일관성이 있다. 
        for(int i=0; i<N; ++i){
            scanf("%s", s);
            if(flag && trie.search(s,trie.root)==0) 
                flag = 0;
            if(flag)trie.insert(s, trie.root);
        }
        puts(flag ? "YES" : "NO");
    }
}
