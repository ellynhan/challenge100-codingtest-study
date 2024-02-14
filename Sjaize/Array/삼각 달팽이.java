// https://school.programmers.co.kr/learn/courses/30/lessons/68645
class Solution {
    int currentNumber = 1;
    public int[] solution(int n) {
        int[] answer = new int[n*(n+1)/2];
        int[] level = getLevel(n);
        drawing(answer, n, level);
        return answer;
    }
    
    private int[] getLevel(int n) {
        int[] level = new int[n*(n+1)/2];
        int num = 1;
        int num_count = 0;
        for (int i = 0; i < level.length; i++) {
            level[i] = num;
            ++num_count;
            if (num_count == num) {
                num = num + 1;
                num_count = 0;
            }
        }
        return level;
    }
    
    private void drawing(int[] snail, int n, int[] level) {
        int height = n;
        snail[0] = 1;
        int currentIndex = 0;
        if (--n != 0) {
            currentIndex = moveDown(snail, n, currentIndex, level);
        }
        while (n != 0) {
            currentIndex = moveRight(snail, n, currentIndex);
            if (--n == 0) break;
            currentIndex = moveUp(snail, n, currentIndex, level);
            if (--n == 0) break;
            currentIndex = moveDown(snail, n, currentIndex, level);
            if (--n == 0) break;
        }
    }
    
    private int moveDown(int[] snail, int drawingBlock, int currentIndex, int[] level)     {
        while (drawingBlock != 0) {
            currentIndex = level[currentIndex] + currentIndex;
            snail[currentIndex] = ++currentNumber;
            --drawingBlock;
        }
        return currentIndex;
    }
    
    private int moveRight(int[] snail, int drawingBlock, int currentIndex) {
        while (drawingBlock != 0) {
            currentIndex = currentIndex + 1;
            snail[currentIndex] = ++currentNumber;
            --drawingBlock;
        }
        return currentIndex;
    }
    
    private int moveUp(int[] snail, int drawingBlock, int currentIndex, int[] level) 
    {
        while (drawingBlock != 0) {
            currentIndex = currentIndex - level[currentIndex];
            snail[currentIndex] = ++currentNumber;
            --drawingBlock;
        }
        return currentIndex;
    }
}
