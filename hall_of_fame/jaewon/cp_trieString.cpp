/*
문자열 검색
*/
#include <cstdio>

const int LM = 200000;
const int CHILD = 26;

struct Trie{
    struct Node{
        int child[CHILD], wordFlag;
        void clear(){
            wordFlag = 0;
            for(int i=0; i<CHILD; ++i)child[i] =0;
        }
    }buf[LM*5];
    int bcnt, root, wordCnt;
    void init(){
        bcnt = root = wordCnt = 0;
        buf[root].clear();
    }
    void insert(char*s, int par = 0){
        for(; *s; ++s){
            int idx = *s -'a';
            if(buf[par].child[idx] == 0)
                buf[par].child[idx] = ++bcnt, buf[bcnt].clear();
            par = buf[par].child[idx];
        }
        buf[par].wordFlag = 1;
        wordCnt ++;
    }
    void erase(char*s, int par=0){
        for(;*s;++s){
            int idx = *s - 'a';
            par = buf[par].child[idx];
        }
        buf[par].wordFlag = 0;
        wordCnt--;
    }
    bool search(char*s, int par =0){
        for(; *s; ++s){
            int idx = *s -'a';
            if(buf[par].child[idx]==0)return 0;
            par = buf[par].child[idx];
        }
        return buf[par].wordFlag;
    }
}trie;

char str[12];
int main(){
    int N;
    scanf("%d", &N);
    trie.init();
    for(int i=0; i<N; ++i){
        scanf("%s", str);
        if(trie.search(str))
            trie.erase(str);
        else trie.insert(str);
    }
    printf("%d\n", trie.wordCnt);
    return 0;
}