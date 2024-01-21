package PGS_60059;

/*
        1. 9 x 9 크기의 map 2차원 배열 생성
        2. 회전을 구현 - static
        3. 회전 + 이동하면서
        4. 중앙부분 모두 채워지는 지 검사
*/

// chap12 구현문제 325p 자물쇠와 열쇠
class Solution {

    public static int[][] rotate90(int[][] array) {
        int row = array.length;
        int col = array[0].length;
        int[][] result = new int[col][row];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                result[j][row - i - 1] = array[i][j];
            }
        }
        return result;
    }

    public static boolean check(int[][] newLock) {
        int lockLength = newLock.length / 3;
        for (int i = lockLength; i < lockLength * 2; i++) {
            for (int j = lockLength; j < lockLength * 2; j++) {
                if (newLock[i][j] != 1) return false;
            }
        }
        return true;
    }

    public boolean solution(int[][] key, int[][] lock) {
        int n = lock.length;
        int m = key.length;

        int[][] newLock = new int[n * 3][n * 3];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                newLock[i + n][j + n] = lock[i][j];
            }
        }

        for (int r = 0; r < 4; r++) {
            key = rotate90(key);
            for (int x = 0; x < n * 2; x++) {
                for (int y = 0; y < n * 2; y++) {
                    for (int i = 0; i < m; i++) {
                        for (int j = 0; j < m; j++) {
                            newLock[x + i][y + j] += key[i][j];
                        }
                    }

                    if (check(newLock)) return true;
                    else {
                        for (int i = 0; i < m; i++) {
                            for (int j = 0; j < m; j++) {
                                newLock[x + i][y + j] -= key[i][j];
                            }
                        }
                    }
                }
            }
        }

        return false;
    }
}

