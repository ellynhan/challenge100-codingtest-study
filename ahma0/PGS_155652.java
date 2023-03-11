
public class Solution {

    public static String solution(String s, String skip, int index) {
        char arr[] = s.toCharArray();

        for(int i = 0; i < s.length(); i++) {
            for(int j = 0; j < index; j++) {
                do {
                    arr[i]++;
                    if(arr[i] > 'z') arr[i] -= 26;
                } while (skip.contains(String.valueOf(arr[i])));
            }
        }
        return String.valueOf(arr);
    }

}