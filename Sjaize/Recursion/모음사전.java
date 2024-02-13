import java.util.ArrayList;
import java.util.List;

class Solution {
    private static final char[] LETTERS = new char[]{'A','E','I','O','U'};
    public int solution(String word) {
        List<String> words = new ArrayList<>();
        generate("", words);
        return words.indexOf(word);
    }
    
    private void generate(String word, List<String> words) {
        words.add(word);
        if (word.length() == 5) return;
        for (char c : LETTERS) generate(word+c, words);
    }
}
