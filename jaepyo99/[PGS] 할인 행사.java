import java.util.*;
class Solution {
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        // 할인 받기를 원하는 제품과 개수를 맵형태로 저장
        Map<String,Integer>wantMap=new HashMap<>();
        int wantLength=want.length;
        for(int i=0;i<wantLength;i++){
            wantMap.put(want[i],number[i]);
        }
        // 10일동안만 할인이 지속되므로 할인되는 제품의 개수-10 만큼 반복문 돌기
        int discountLength=discount.length;
        for(int i=0;i<=discount.length-10;i++){
            Map<String,Integer>discountMap=new HashMap<>();
            // 시작부터 10개만큼 돌고, 해당 범위안에 각 제품이 몇개포함되어 있는지 맵에 저장
            for(int j=0;j<10;j++){
                String item=discount[i+j];
                Integer count=discountMap.getOrDefault(item,0);
                count++;
                discountMap.put(item,count);
            }
            boolean isSignup=true;
            // 원하는 제품의 개수가 범위안의 제품의 개수와 비교했을때 맞게 있는지 확인하고 조건이 만족하면 true 못 만족하면 false
            for(String wantItem:wantMap.keySet()){
                int wantCount=wantMap.get(wantItem);
                int discountCount=discountMap.getOrDefault(wantItem,0);
                if(wantCount>discountCount){
                    isSignup=false;
                    break;
                }
            }
            // 만족됬으면 answer ++
            if(isSignup){
                answer++;
            }
        }
        return answer;
    }
}
