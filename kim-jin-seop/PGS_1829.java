package programmers_1829;

class Solution {
    public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;

        boolean[][] check = new boolean[m][n];

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!check[i][j] && picture[i][j] != 0) {
                    int count = group(i, j, picture, check);
                    if(maxSizeOfOneArea < count){
                        maxSizeOfOneArea = count;
                    }
                    numberOfArea++;
                }
            }
        }

        int[] answer = new int[2];
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }


    private int group(int x, int y, int[][] picture, boolean[][] check) {
        check[x][y] = true;
        int count = 1;
        int[] dx = {-1,0,1,0};
        int[] dy = {0,1,0,-1};

        for(int z = 0; z < 4; z++){
            int checkX = x + dx[z];
            int checkY = y + dy[z];
            if(checkX >= 0 && checkX < picture.length && checkY >= 0 && checkY < picture[0].length){
                if(check[checkX][checkY])
                    continue;
                if(picture[checkX][checkY] == picture[x][y])
                    count += group(checkX,checkY,picture,check);
            }
        }
        return count;
    }
}