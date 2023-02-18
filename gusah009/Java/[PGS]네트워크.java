class Solution {

  boolean[] isVisited = new boolean[200];

  public int solution(int n, int[][] computers) {
    int answer = 0;
    answer = solve(n, computers, answer);
    return answer;
  }

  private int solve(int n, int[][] computers, int answer) {
    for (int i = 0; i < n; i++) {
      if (!isVisited[i]) {
        isVisited[i] = true;
        dfs(i, computers, n);
        answer++;
      }
    }
    return answer;
  }

  private void dfs(int currNode, int[][] computers, int n) {
    for (int nextNode = 0; nextNode < n; nextNode++) {
      if (computers[currNode][nextNode] == 1) {
        if (!isVisited[nextNode]) {
          isVisited[nextNode] = true;
          dfs(nextNode, computers, n);
        }
      }
    }
  }
}