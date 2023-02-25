#include <iostream>
#include <vector>
#define MAX 26
using namespace std;

struct Node {
    char left;
    char right;
};
int N; 
vector<Node> tree(MAX);

void Input()
{
    cin >> N;
    char p, lc, rc;
    for(int i=0; i<N; i++)
    {
        cin >> p >> lc >> rc;
        tree[p] = {lc, rc};
    }
}

void preorder(char curr)
{   
    if(curr == '.') return;
    cout << curr;
    preorder(tree[curr].left);
    preorder(tree[curr].right);
}

void inorder(char curr)
{
    if(curr == '.') return;
    inorder(tree[curr].left);
    cout << curr;
    inorder(tree[curr].right);
}

void postorder(char curr)
{
    if(curr == '.') return;
    postorder(tree[curr].left);
    postorder(tree[curr].right);
    cout << curr;
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    Input();
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
}