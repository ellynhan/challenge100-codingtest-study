//
//  24060.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/10.
//

/*
 [Input]
 5 7
 4 5 1 3 2
 [Output]
 3
 */
// 시간복잡도: O(nlogn)
// 최악시간: 2,500,000
// 난이도: Silver 4
// Timer: 15m
// Url: https://www.acmicpc.net/problem/24060

#include <iostream>

using namespace std;
int ans, cnt;
int n, k;
int a[500001];

// A[p..q]와 A[q+1..r]을 병합하여 A[p..r]을 오름차순 정렬된 상태로 만든다.
// A[p..q]와 A[q+1..r]은 이미 오름차순으로 정렬되어 있다.
void merge(int* A, int p, int q, int r) {
    int i = p;
    int j = q + 1;
    int t = 1;
    int tmp[n];
    
    while(i <= q && j <= r) {
        if(A[i] <= A[j])
            tmp[t++] = A[i++]; // tmp[t] <- A[i]; t++; i++;
        else
            tmp[t++] = A[j++]; // tmp[t] <- A[j]; t++; j++;
    }
    while(i <= q)   // 왼쪽 배열 부분이 남은 경우
        tmp[t++] = A[i++];
    while(j <= r)   // 오른쪽 배열 부분이 남은 경우
        tmp[t++] = A[j++];
    i = p;
    t = 1;
    while(i <= r) {  // 결과를 A[p..r]에 저장
        cnt++;
        if(cnt == k) ans = tmp[t];
        A[i++] = tmp[t++];
    }
}

// A[p..r]을 오름차순 정렬한다.
void merge_sort(int* A, int p, int r) {
    if(p < r) {
        int q = (p + r) / 2;        // q는 p, r의 중간 지점
        merge_sort(A, p, q);        // 전반부 정렬
        merge_sort(A, q + 1, r);    // 후반부 정렬
        merge(A, p, q, r);          // 병합
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    merge_sort(a, 0, n - 1);
    if(ans == 0) cout << -1;
    else cout << ans;
    
    return 0;
}
