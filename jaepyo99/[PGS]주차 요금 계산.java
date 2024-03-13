import java.util.*;
class Solution {
    public List<Integer> solution(int[] fees, String[] records) {
        Map<String,String>InMap=new HashMap<>();
        Map<String,Integer>resultMap=new TreeMap<>();
        
        for(String record:records){
            String[] parse=record.split(" ");
            if(parse[2].equals("IN")){
                System.out.println("IN : "+parse[1]+" "+parse[0]);
                InMap.put(parse[1],parse[0]);
            }else{
                System.out.println("OUT : "+parse[1]+" "+parse[0]);
                
                String inDate=InMap.get(parse[1]);
                String outDate=parse[0];
                
                InMap.remove(parse[1]);
                
                String[] parseIn=inDate.split(":");
                String[] parseOut=outDate.split(":");
                
                Integer[] in={Integer.valueOf(parseIn[0]),Integer.valueOf(parseIn[1])};
                Integer[] out={Integer.valueOf(parseOut[0]),Integer.valueOf(parseOut[1])};
                Integer totalTime=(out[0]-in[0])*60+(out[1]-in[1]);
                
                resultMap.put(parse[1],resultMap.getOrDefault(parse[1],0)+totalTime);
            }
        }
        if(InMap.size()!=0){
            for(String a:InMap.keySet()){
                String inDate=InMap.get(a);
                String[] parseIn=inDate.split(":");
                Integer[] in={Integer.valueOf(parseIn[0]),Integer.valueOf(parseIn[1])};
                
                Integer totalTime=(23-in[0])*60+(59-in[1]);
                resultMap.put(a,resultMap.getOrDefault(a,0)+totalTime);
            }
        }
        List<Integer>answer=new ArrayList<>();
        
        for(String key:resultMap.keySet()){
            Integer totalFee=0;
            Integer totalTime=resultMap.get(key);
            if(totalTime<=fees[0]){
                totalFee+=fees[1];
                totalTime=0;
            }else{
                totalTime-=fees[0];
                totalFee+=fees[1];
            }
            Integer t = totalTime/fees[2];
            if(totalTime%fees[2]>0){
                t+=1;
            }
            totalFee+=t*fees[3];
            answer.add(totalFee);
        }
        
        return answer;
    }
}
