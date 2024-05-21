import java.util.*;
class Solution {
    public int[] solution(String[] gems) {
        int kind=new HashSet<>(Arrays.asList(gems)).size(); // 주어진 보석의 종류
        int[]answer=new int[2]; //범위를 위한 배열
        int length=Integer.MAX_VALUE,start=0; // length는 진열대의 길이(비교를 위해 큰숫자), start는 진열대의 시작인덱스
        Map<String,Integer>map=new HashMap<>(); // 선택한 진열대에 있는 각 보석의 개수
        for(int end=0;end<gems.length;end++){
            map.put(gems[end],map.getOrDefault(gems[end],0)+1); // 내가 선택한 진열대의 보석 업데이트
            while(map.get(gems[start])>1){ // 방금 선택으로 가장 왼쪽에 있는 보석이 여러개가 되었다면 보석의 개수를 줄이기 위해 1감소
                map.put(gems[start],map.get(gems[start])-1);
                start++;
            }
            if(map.size()==kind && length>(end-start)){
                // 현재까지 선택한 진열대에 모든 보석이 있고, 길이가 짧다면 인덱스 업데이트
                length=end-start;
                answer[0]=start+1;
                answer[1]=end+1;
            }
        }
        // for문을 통해 가장 왼쪽에서 보석의 종류가 채워지는 최초의 배열을 찾은뒤, 이후의 조합중에 개수가 더 적은 배열이 있는지 찾는 방식
        return answer;
    }
}
