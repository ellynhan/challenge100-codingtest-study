import java.util.*;
class Solution {
    public String convert(String sen,Boolean b){
        if(b==false){
            return sen+"님이 들어왔습니다.";
        }else{
            return sen+"님이 나갔습니다.";
        }
    }
    public String[] solution(String[] records) {
        List<String> answer=new ArrayList<>();
        
        Map<String,String>name=new HashMap<>();
        Map<String,Boolean>isEnter=new HashMap<>();
        List<String>list=new ArrayList<>();
        
        for(String record:records){
            String[] informs=record.split(" ");
            if(informs[0].equals("Enter")){
                name.put(informs[1],informs[2]);
                list.add(informs[1]);
            }else if(informs[0].equals("Leave")){
                list.add(informs[1]);
            }else{
                name.put(informs[1],informs[2]);
            }
        }
        
        for(String record:records){
            String[] informs=record.split(" ");
            if(informs[0].equals("Enter")){
                answer.add(convert(name.get(informs[1]),false));
            }else if(informs[0].equals("Leave")){
                answer.add(convert(name.get(informs[1]),true));
            }
        }
        
        
        return answer.toArray(new String[answer.size()]);
    }
}
