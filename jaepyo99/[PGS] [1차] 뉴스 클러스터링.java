import java.util.*;
class Solution {
    public String remainAlp(String s){
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<s.length();i++){
            if(!(s.charAt(i)>='A' && s.charAt(i)<='Z')){
                continue;
            }
            sb.append(s.charAt(i));
        }
        return sb.toString();
    }
    
    public List<String> splitTwo(String s){
        List<String>list=new ArrayList<>();
        for(int i=0;i<s.length()-1;i++){
            Character a=s.charAt(i);
            Character b=s.charAt(i+1);
            if(!((a>='A'&&a<='Z') && (b>='A'&&b<='Z'))){
                continue;
            }
            StringBuilder sb=new StringBuilder();
            sb.append(s.charAt(i));
            sb.append(s.charAt(i+1));
            list.add(sb.toString());
        }
        return list;
    }
    public void print(List<String> s){
        for(int i=0;i<s.size();i++){
            System.out.print(s.get(i));
            System.out.print(" ");
        }
        System.out.println();
        
    }
    public int solution(String str1, String str2) {
        int answer = 0;
        str1=str1.toUpperCase();
        str2=str2.toUpperCase();
        List<String> str1List=splitTwo(str1);
        List<String> str2List=splitTwo(str2);
        print(str1List);
        print(str2List);
        List<String>union=new ArrayList<>();
        List<String>inter=new ArrayList<>();
        for(int i=0;i<str2List.size();i++){
            if(str1List.remove(str2List.get(i))){
                union.add(str2List.get(i));
            }
            inter.add(str2List.get(i));
        }
        for(int i=0;i<str1List.size();i++){
            inter.add(str1List.get(i));
        }
        
        if(inter.size()==0){
            return 65536;
        }
        return (int)(((double)union.size()/(double)inter.size())*65536);
    }
}
