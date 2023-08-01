/*
    구간의 최대값
*/
#include <cstdio>
int elem[50001]={0};
inline int Max(int a, int b){return a>b ? a : b;}

struct Node{
    int start, end, maxValue;
    Node* left = NULL;
    Node* right = NULL;
};

void buildTree(int start, int end, Node* node){
    node->start = start;
    node->end = end;
    if(start == end){
        node->maxValue = elem[start];
    }else{
        node->left = new Node();
        node->right = new Node();
        int mid = (start+end)/2;
        buildTree(start, mid, node->left);
        buildTree(mid+1, end, node->right);
        node->maxValue = Max(node->left->maxValue, node->right->maxValue);
    }
}

void dfs(Node* node){
    if(node!=NULL){
        printf("( %d , %d )maxValue: %d\n", node->start, node->end, node->maxValue);
        dfs(node->left);
        dfs(node->right);
    }
}

int search(int qstart, int qend, Node* node){
    if(qstart <= node->start && qend >= node->end){
        return node->maxValue;
    }else if(qend < node->start || qstart > node->end){
        return 0;
    }else{
        int left = search(qstart, qend, node->left);
        int right = search(qstart, qend, node->right);
        return Max(left, right);
    }
}

int main(){
    int N,Q;
    scanf("%d%d",&N,&Q);
    for(int i=1; i<=N; i++){
        scanf("%d",&elem[i]);
    }
    Node root = Node();
    buildTree(1,N,&root);
    // dfs(&root);
    while(Q--){
        int A,B;
        scanf("%d%d",&A,&B);
        printf("%d\n",search(A,B,&root));
    }
}