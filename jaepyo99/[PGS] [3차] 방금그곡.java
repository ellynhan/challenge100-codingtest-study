import java.util.*;
class Solution {
    int max_time=-1;
    String max_play;
    
    public int toMin(int hour, int minute){
        return hour*60+minute;
    }
    public int calDuring(String[] s, String[] e){
        int startMin=toMin(Integer.parseInt(s[0]),Integer.parseInt(s[1]));
        int endMin=toMin(Integer.parseInt(e[0]),Integer.parseInt(e[1]));
        return endMin-startMin;
    }
    public String search(String start, String end, String music){

        int during=calDuring(start.split(":"),end.split(":"));
        int a=during/music.length();
        int b=during%music.length();
        
        return music.repeat(a).concat(music.substring(0,b));
    }
    public String change(String original){
        original=original.replace("C#","H");
        original=original.replace("D#","I");
        original=original.replace("F#","J");
        original=original.replace("G#","K");
        original=original.replace("A#","L");
        original=original.replace("B#","P");
        return original;
    }
    public String solution(String m, String[] musics) {
        String answer = "";
        for(int i=0;i<musics.length;i++){
            String[] music = musics[i].split(",");
            String sen=search(music[0],music[1],change(music[3]));
            if(sen.contains(change(m))){
                if(max_time<calDuring(music[0].split(":"),music[1].split(":"))){
                    max_time=calDuring(music[0].split(":"),music[1].split(":"));
                    max_play=music[2];
                }
            }
        }
        if(max_time==-1){
            return "(None)";
        }
        return max_play;
    }

}
