#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int *tree;
int *is_zero;
int n;

int InitTree(int s, int e, int node)
{
    if (s == e)
    {
        if( v[s] == 0 ) {
            is_zero[node] ++;
            return tree[node] = 1;
        }
        return tree[node] = v[s];
    }

    int mid = (s + e) / 2;

    
    tree[node] = InitTree(s, mid, node * 2) * InitTree(mid + 1, e, node * 2 + 1);
    is_zero[node] = is_zero[node*2] + is_zero[node*2+1];

    return tree[node];
}

int FindProd(int s, int e, int find_s, int find_e, int node)
{
    int mid = (s + e) / 2;
    if (find_s == s && find_e == e)
    {
        if( is_zero[node] > 0 )
            return 0;
        return tree[node];
    }
    else if (find_e <= mid)
    { 
        return FindProd(s, mid, find_s, find_e, node * 2);
    }
    else if (mid < find_s)
    {
        return FindProd(mid + 1, e, find_s, find_e, node * 2 + 1);
    }

    return FindProd(s, mid, find_s, mid, node * 2) * FindProd(mid + 1, e, mid + 1, find_e, node * 2 + 1);
}

void UpdateTree(int s, int e, int idx, int node, int newValue)
{
    if (s == idx && e == idx)
    {
        if( v[idx] == 0 ){
            is_zero[node] --;
        }
        if( newValue == 0 ) {
            is_zero[node] ++;
            tree[node] = 1;
        }
        else {
            tree[node] = newValue;
        }
        
        v[idx] = newValue;
        return;
    }

    int mid = (s + e) / 2;

    if (idx <= mid)
    {
        if( v[idx] == 0 ){
            is_zero[node] --;
        }
        else {
            tree[node] /= v[idx];
        }
        if( newValue == 0 ) {
            is_zero[node] ++;
        }
        else {
            tree[node] *= newValue;
        }
        UpdateTree(s, mid, idx, node * 2, newValue);
        return;
    }
    else if (mid < idx)
    {
        if( v[idx] == 0 ){
            is_zero[node] --;
        }
        else {
            tree[node] /= v[idx];
        }
        if( newValue == 0 ) {
            is_zero[node] ++;
        }
        else {
            tree[node] *= newValue;
        }
        UpdateTree(mid + 1, e, idx, node * 2 + 1, newValue);
        return;
    }
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, t;
    char cmd;
    int a, b;
    string result;

    while( cin >> n ) {
        v.clear();
        result.clear();
        cin >> k;
        //cout << "n : " << n << " k : " << k << '\n';
        tree = new int[4*n];
        is_zero = new int[4*n];
        memset(tree, 0, sizeof(int)*4*n);
        memset(is_zero, 0, sizeof(int)*4*n);

        v.push_back(0);

        for( int i=0; i<n; i++ ) {
            cin >> t;
            if( t > 0 ) 
                t = 1;
            if( t < 0 )
                t = -1;
            v.push_back(t);
        }

        InitTree( 1, n, 1 );

        for( int i=0; i<k; i++ ) {
            cin >> cmd >> a >> b;
            if( cmd == 'C' ) {
                if( b > 0 ) 
                    b = 1;
                if( b < 0 )
                    b = -1;
                UpdateTree(1, n, a, 1, b);
                v[a] = b;
            }
            else {
                int r = FindProd( 1, n, a, b, 1 );
                //cout << r << '\n';
                if( r == 0 )
                    result.push_back('0');
                else if( r < 0 )
                    result.push_back('-');
                else if( r > 0 )
                    result.push_back('+');
            }
        }
        cout << result << '\n';
        delete[] tree;
    }
    return 0;
}