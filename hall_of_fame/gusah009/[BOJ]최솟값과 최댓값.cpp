#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define MAX 100001

int N, M;
int arr[MAX];
int max_segment_tree[4 * MAX];
int min_segment_tree[4 * MAX];

int makeMaxSegmentTree(int node, int start, int end)
{
  if (start == end) return max_segment_tree[node] = arr[start];
  
  int Mid = (start + end) / 2;
  int Left_Result = makeMaxSegmentTree(node * 2, start, Mid);
  int Right_Result = makeMaxSegmentTree(node * 2 + 1, Mid + 1, end);
  max_segment_tree[node] = max(Left_Result, Right_Result);

  return max_segment_tree[node];
}

int makeMinSegmentTree(int node, int start, int end)
{
  if (start == end) return min_segment_tree[node] = arr[start];
  
  int Mid = (start + end) / 2;
  int Left_Result = makeMinSegmentTree(node * 2, start, Mid);
  int Right_Result = makeMinSegmentTree(node * 2 + 1, Mid + 1, end);
  min_segment_tree[node] = min(Left_Result, Right_Result);

  return min_segment_tree[node];
}

int find_max_element(int node, int start, int end, int left, int right)
{
    if (left > end || right < start) return 0;
    
    if (left <= start && end <= right) return max_segment_tree[node];
 
    int Mid = (start + end) / 2;
    int left_Result = find_max_element(node * 2, start, Mid, left, right);
    int right_Result = find_max_element(node * 2 + 1, Mid + 1, end, left, right);
    return max(left_Result, right_Result);
}

int find_min_element(int node, int start, int end, int left, int right)
{
    if (left > end || right < start) return INT32_MAX;
    
    if (left <= start && end <= right) return min_segment_tree[node];
 
    int Mid = (start + end) / 2;
    int left_Result = find_min_element(node * 2, start, Mid, left, right);
    int right_Result = find_min_element(node * 2 + 1, Mid + 1, end, left, right);
    return min(left_Result, right_Result);
}
// 출처: https://yabmoons.tistory.com/431 [얍문's Coding World..]

void input_solve_print()
{
  cin >> N >> M;
  FOR(n, N) {
    cin >> arr[n];
  }

  makeMaxSegmentTree(1, 0, N - 1);
  makeMinSegmentTree(1, 0, N - 1);

  int a, b;
  FOR(m, M) {
    cin >> a >> b;
    cout << find_min_element(1, 0, N - 1, a - 1, b - 1) <<  ' ' 
         << find_max_element(1, 0, N - 1, a - 1, b - 1) << '\n';
  }
}

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input_solve_print();
}