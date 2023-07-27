import java.util.*;
import java.io.*;

public class Main{
    static int[] inputData;
    static int[] segmentTree;

    public static int compare(int indexA, int indexB){
        assert(indexA != indexB);
        if(indexA == Integer.MAX_VALUE || indexB == Integer.MAX_VALUE)
            return Integer.min(indexA, indexB);
        int result;
        if(inputData[indexA] > inputData[indexB]){
            result = indexB;
        }else if(inputData[indexA] < inputData[indexB]){
            result = indexA;
        }else{
            result = Integer.min(indexA, indexB);
        }
        return result;
    }

    public static int init(int start, int end, int nodeIdx){
        if(start == end)
            return segmentTree[nodeIdx] = start;
        else{
            int mid = (start + end) / 2;
            int resultA = init(start, mid, nodeIdx*2);
            int resultB = init(mid+1, end, nodeIdx*2+1);
            int result = compare(resultA, resultB);
            return segmentTree[nodeIdx] = result;
        }
    }

    public static int update(int start, int end, int targetIdx, int nodeIdx, int newValue){
        if(start > targetIdx || end < targetIdx)
            return segmentTree[nodeIdx];
        if(start == end){
            inputData[targetIdx] = newValue;
            return segmentTree[nodeIdx];
        }
        int mid = (start + end) / 2;

        return segmentTree[nodeIdx] = compare(update(start, mid, targetIdx, nodeIdx*2, newValue), update(mid+1, end, targetIdx, nodeIdx*2 + 1, newValue));
    }

    public static int min(int start, int end, int targetstart, int targetEnd, int nodeIdx){
        if(start > targetEnd || end < targetstart)
            return Integer.MAX_VALUE;

        if(start >= targetstart && end <= targetEnd){
            return segmentTree[nodeIdx];
        }

        int mid = (start + end) / 2;
        return compare(min(start, mid, targetstart, targetEnd, nodeIdx * 2), min(mid+1, end, targetstart, targetEnd, nodeIdx*2 +1));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(re.readLine());

        inputData = new int[n];
        segmentTree = new int[4*n];

        StringTokenizer token = new StringTokenizer(re.readLine());
        for(int i = 0; i < n; i++){
            inputData[i] = Integer.parseInt(token.nextToken());
        }
        
        init(0, n-1, 1);

        StringBuilder ans=  new StringBuilder();
        int query = Integer.parseInt(re.readLine());
        for(int i = 0; i < query; i++){
            token = new StringTokenizer(re.readLine());
            int type = Integer.parseInt(token.nextToken());
            if(type == 1){
                int target = Integer.parseInt(token.nextToken()) - 1;
                int newValue = Integer.parseInt(token.nextToken());

                update(0, n-1, target, 1, newValue);
            }else{
                int start = Integer.parseInt(token.nextToken()) -1;
                int end = Integer.parseInt(token.nextToken()) - 1;

                ans.append(min(0, n-1, start, end, 1)+1).append('\n');
            }
        }
        System.out.print(ans);
        re.close();
    }
}