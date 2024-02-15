// https://school.programmers.co.kr/learn/courses/30/lessons/81302
class Solution {
    public int[] solution(String[][] places) {
        int[] answer = new int[5];
        for (int index = 0; index < 5; index++) {
            char[][] arr = new char[5][5];
            for (int i = 0; i < 5; i++) {
                arr[i] = places[index][i].toCharArray();
            }
            answer[index] = isKeepDistance(arr);
        }
        return answer;
    }
    private int isKeepDistance(char[][] arr) {
        int[] drow = {-1, 0, 1, 0, -2, 0, 2, 0, -1, 1, 1, -1};
        int[] dcol = {0, 1, 0, -1, 0, 2, 0, -2, 1, 1, -1, -1};
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (arr[i][j] == 'P') {
                    for (int k = 0; k < 12; k++) {
                        int nrow = i + drow[k];
                        int ncol = j + dcol[k];
                        if (nrow > 4 || nrow < 0 || ncol > 4 || ncol < 0) continue;
                        if (arr[nrow][ncol] == 'P') {
                            if (k < 4) return 0;
                            if (k >= 4 && k < 8) {
                                if (arr[i+drow[k]/2][j+dcol[k]/2] != 'X') {
                                    return 0;
                                }
                            }
                            if (k >= 8) {
                                if (arr[nrow][j] != 'X' || arr[i][ncol] != 'X') {
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
        return 1;
    }
}
