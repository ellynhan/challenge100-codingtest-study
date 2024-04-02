import java.util.*;
class Solution {
    char[][] arr;
    int row, col;
    boolean[][] visited; // 방문한 노드를 표시하기 위한 배열

    public int dfs(int r, int c) {
        int sum = 0;
        if (r < 0 || r >= row || c < 0 || c >= col || arr[r][c] == 'X' || visited[r][c]) { // 범위를 벗어나거나 이미 방문한 노드인 경우
            return 0;
        }
        visited[r][c] = true; // 방문한 노드 표시

        sum += dfs(r + 1, c);
        sum += dfs(r - 1, c);
        sum += dfs(r, c + 1);
        sum += dfs(r, c - 1);

        sum += Character.getNumericValue(arr[r][c]);
        return sum;
    }

    public int[] solution(String[] maps) {
        List<Integer> list = new ArrayList<>();

        row = maps.length;
        col = maps[0].length();
        arr = new char[row][col];
        visited = new boolean[row][col]; // 방문한 노드 배열 초기화

        for (int i = 0; i < row; i++) {
            arr[i] = maps[i].toCharArray();
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (arr[i][j] != 'X' && !visited[i][j]) { // 'X'가 아니고 방문하지 않은 노드인 경우에만 DFS 수행
                    list.add(dfs(i, j));
                }
            }
        }
        int[] answer;
        if (list.size() == 0) {
            answer = new int[1];
            answer[0] = -1;
        } else {
            answer = new int[list.size()];
            for (int i = 0; i < list.size(); i++) {
                answer[i] = list.get(i);
            }
        }
        Arrays.sort(answer);
        return answer;
    }
}
