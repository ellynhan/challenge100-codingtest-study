#include <bits/stdc++.h>

#define ABS(x) (x<0 ? -x : x)

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> heap;
    int n;
    int idx = 1;
    int cmd;
    
    heap.push_back(0);

    cin >> n;
    for( int i=0; i<n; i++ ) {
        cin >> cmd;
        if( cmd == 0 ) {
            if( heap.size() == 1 ) {
                cout << 0 << '\n';
            }
            else {
                cout << heap[1] << '\n';
                heap[1] = heap[idx-1];
                heap.pop_back();
                idx --;

                int k = 2;
                while( k < idx ) {
                    if( k < idx-1 
                        && ( ABS(heap[k+1]) < ABS(heap[k]) || ABS(heap[k+1]) == ABS(heap[k]) && heap[k+1] < heap[k] ) ) {
                        k ++;
                    }
                    if( ABS(heap[k]) < ABS(heap[k/2]) || (ABS(heap[k]) == ABS(heap[k/2]) && heap[k] < heap[k/2]) ) {
                        int t = heap[k];
                        heap[k] = heap[k/2];
                        heap[k/2] = t;
                    }
                    k *= 2;
                }
            }
        }
        else {
            heap.push_back(cmd);
            idx ++;
            int k = idx-1;
            while( k > 1 ) {
                if( ABS(heap[k]) < ABS(heap[k/2]) || (ABS(heap[k]) == ABS(heap[k/2]) && heap[k] < heap[k/2]) ) {
                    int t = heap[k];
                    heap[k] = heap[k/2];
                    heap[k/2] = t;
                }
                k /= 2;
            }
        }
    }

    return 0;
}