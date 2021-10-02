#include <bits/stdc++.h>

using namespace std;

int heap[100001] = {0, };
int len = 0;

void push(int n)
{
    ++ len;
    int idx = len;
    heap[len] = n;
    while(idx > 1 && heap[idx] > heap[idx/2])
    {
        int tmp = heap[idx];
        heap[idx] = heap[idx/2];
        heap[idx/2] = tmp;
        idx /= 2;
    }
}

int pop(void)
{
    int idx = 1;
    int tmp;
    if(len == 0)
        return 0;
    int ret = heap[1];
    heap[1] = heap[len];
    heap[len--] = 0;
    while(idx*2 <= len)
    {
        if(heap[idx] < max(heap[idx*2], heap[idx*2+1]))
        {
            tmp = heap[idx];
            if(heap[idx*2] > heap[idx*2+1]){
                heap[idx] = heap[idx*2];
                heap[idx*2] = tmp;
                idx = idx * 2;
            }
            else{
                heap[idx] = heap[idx * 2 + 1];
                heap[idx * 2 + 1] = tmp;
                idx = idx * 2 + 1;
            }
        }
        else{
            break;
        }
    }
    return ret;
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t;

    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> t;
        if(t == 0) {
            cout << pop() << '\n';
        }
        else {
            push(t);
        }
    }

    return 0;
}