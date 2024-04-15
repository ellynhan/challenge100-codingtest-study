class Solution {
    public int solution(String s) {
        int n=s.length();
        int answer = n;
        for(int i=1;i<=n/2;i++){
            int zipLength=1;
            String zipStr=s.substring(0,i);
            StringBuilder sb=new StringBuilder();
            for(int j=i;j<=n;j+=i){
                String nextStr=s.substring(j,(j+i>n)?n:j+i);
                if(zipStr.equals(nextStr)){
                    zipLength++;
                }else{
                    sb.append((zipLength!=1 ? zipLength:"")+zipStr);
                    zipStr=nextStr;
                    zipLength=1;
                }
            }
            sb.append(zipStr);
            answer=Math.min(answer,sb.length());
        }
        return answer;
    }
}
