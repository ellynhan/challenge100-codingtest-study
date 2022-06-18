import java.util.*;
import java.io.*;

class SegmentTree {
    int[] originData;
    int[] treeData;

    SegmentTree(int[] inputData) {
        treeData = new int[inputData.length * 4];
        originData = inputData;
    }

    int init(int nowStart, int nowEnd, int node) {
        if (nowStart == nowEnd)
            return treeData[node] = originData[nowStart];

        int mid = (nowStart + nowEnd) / 2;

        int leftSubTree = init(nowStart, mid, node * 2);
        int rightSubTree = init(mid + 1, nowEnd, node * 2 + 1);

        return treeData[node] = Integer.min(leftSubTree, rightSubTree);
    }

    int getMin(int nowStart, int nowEnd, int searchStart, int searchEnd, int node) {
        if (nowStart > searchEnd || nowEnd < searchStart)
            return Integer.MAX_VALUE;

        if (nowStart >= searchStart && nowEnd <= searchEnd)
            return treeData[node];

        int mid = (nowStart + nowEnd) / 2;
        int leftSubTree = getMin(nowStart, mid, searchStart, searchEnd, node * 2);
        int rightSubTree = getMin(mid + 1, nowEnd, searchStart, searchEnd, node * 2 + 1);

        return Integer.min(leftSubTree, rightSubTree);
    }

    int update(int nowStart, int nowEnd, int targetIdx, int node) {
        if (targetIdx < nowStart || targetIdx > nowEnd) {
            return treeData[node];
        }
        if (nowStart == nowEnd) {
            return treeData[node] = originData[targetIdx];
        } else {
            int mid = (nowStart + nowEnd) / 2;
            return treeData[node] = Integer.min(
                    update(nowStart, mid, targetIdx, node * 2),
                    update(mid + 1, nowEnd, targetIdx, node * 2 + 1));
        }
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(re.readLine());

        int[] inputData = new int[n + 1];

        StringTokenizer token = new StringTokenizer(re.readLine());
        for (int i = 1; i <= n; i++) {
            inputData[i] = Integer.parseInt(token.nextToken());
        }

        SegmentTree tree = new SegmentTree(inputData);
        tree.init(1, n, 1);

        int query = Integer.parseInt(re.readLine());

        StringBuilder ans = new StringBuilder();
        for (int q = 0; q < query; q++) {
            token = new StringTokenizer(re.readLine());
            int type = Integer.parseInt(token.nextToken());

            if (type == 1) {
                int index = Integer.parseInt(token.nextToken());
                int newValue = Integer.parseInt(token.nextToken());
                inputData[index] = newValue;
                tree.update(1, n, index, 1);
            } else {
                ans.append(
                        tree.getMin(1, n, Integer.parseInt(token.nextToken()), Integer.parseInt(token.nextToken()), 1))
                        .append('\n');
            }
        }
        System.out.print(ans);
        re.close();
    }
}