// https://school.programmers.co.kr/learn/courses/30/lessons/181832
class Solution {
    final static int[] dx = {0, 1, 0, -1};
    final static int[] dy = {1, 0, -1, 0};
    
    public int[][] solution(int n) {
        int result[][] = new int[n][n];
        int v = 1;
        int x = 0;
        int y = 0;
        int d = 0;
        
        while (true) {
            result[x][y] = v++;
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            if (nx == n || nx == -1 || ny == n || ny == -1 || result[nx][ny] != 0) {
                d = (d + 1) % 4;
                nx = x + dx[d];
                ny = y + dy[d];
                if (nx == n || nx == -1 || ny == n || ny == -1 || result[nx][ny] != 0)
                    break;
            }
            
            x = nx;
            y = ny;
        }
        
        return result;
    }
}
