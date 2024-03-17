import java.util.*;
class Solution {
    public int solution(String dirs) {
        int answer = 0;
        int pos=60;
        int dx=5,dy=5;
        int tmppos=0;
        String[] dirList=dirs.split("");
        Map<Integer,List<String>> map=new HashMap<>();
        for(String dir:dirList){
            System.out.println("DIR: "+dir);
            System.out.println("POS: "+pos);
            if(dir.equals("L")&&dx-1>=0){
                dx-=1;
                
                List<String>nowList=map.getOrDefault(pos,new ArrayList<String>());
                tmppos=pos-1;                
                List<String>changeList=map.getOrDefault(tmppos,new ArrayList<String>());
                
                if(nowList.contains(dir) || changeList.contains("R")){
                pos-=1;
                    continue;
                }
                
                nowList.add(dir);
                changeList.add("R");
                map.put(pos,nowList);
                map.put(tmppos,changeList);
                answer++;
                pos-=1;
            }else if(dir.equals("R")&&dx+1<=10){
                dx+=1;
                List<String>nowList=map.getOrDefault(pos,new ArrayList<String>());
                tmppos=pos+1;                
                List<String>changeList=map.getOrDefault(tmppos,new ArrayList<String>());
                
                if(nowList.contains(dir) || changeList.contains("L")){
                pos+=1;
                    continue;
                }
                
                nowList.add(dir);
                changeList.add("L");
                map.put(pos,nowList);
                map.put(tmppos,changeList);
                answer++;
                
                pos+=1;
            }else if(dir.equals("U")&&dy-1>=0){
                dy-=1;
                
                List<String>nowList=map.getOrDefault(pos,new ArrayList<String>());
                tmppos=pos-11;                
                List<String>changeList=map.getOrDefault(tmppos,new ArrayList<String>());
                
                if(nowList.contains(dir) || changeList.contains("D")){
                pos-=11;
                    continue;
                }
                
                nowList.add(dir);
                changeList.add("D");
                map.put(pos,nowList);
                map.put(tmppos,changeList);
                answer++;
                
                pos-=11;
            }else if(dir.equals("D")&&dy+1<=10){
                dy+=1;
                
                List<String>nowList=map.getOrDefault(pos,new ArrayList<String>());
                tmppos=pos+11;                
                List<String>changeList=map.getOrDefault(tmppos,new ArrayList<String>());
                
                if(nowList.contains(dir) || changeList.contains("U")){
                pos+=11;
                    
                    continue;
                }
                
                nowList.add(dir);
                changeList.add("U");
                map.put(pos,nowList);
                map.put(tmppos,changeList);
                answer++;
                
                pos+=11;
            }else{
                continue;
            }
            System.out.println("ANSWER:"+answer);
            
        }
        return answer;
    }
}
