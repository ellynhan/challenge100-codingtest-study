import java.util.*;
import java.io.*;

class Trie {
    Map<Character, Trie> children = new HashMap<>();

    void insert(String word) {
        Trie now = this;

        for (int i = 0, length = word.length(); i < length; i++) {
            now = now.children.computeIfAbsent(word.charAt(i), k -> new Trie());
        }
        return;
    }

    boolean search(String word) {
        Trie now = this;

        for (int i = 0, length = word.length(); i < length; i++) {
            now = now.children.getOrDefault(word.charAt(i), null);
            if (now == null)
                return false;
        }
        return true;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        int testCase = Integer.parseInt(re.readLine());

        StringBuilder ans = new StringBuilder();
        test: for (int t = 1; t <= testCase; t++) {
            int n = Integer.parseInt(re.readLine());
            String[] inputData = new String[n];

            for (int i = 0; i < n; i++) {
                inputData[i] = re.readLine();
            }

            Arrays.sort(inputData, Collections.reverseOrder());
            Trie trie = new Trie();
            for (String s : inputData) {
                if (trie.search(s)) {
                    ans.append("NO").append('\n');
                    continue test;
                } else {
                    trie.insert(s);
                }
            }
            ans.append("YES").append('\n');
        }
        System.out.print(ans);
        re.close();
    }
}