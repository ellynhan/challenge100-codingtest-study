import java.util.*;
import java.io.*;

class Trie {
    Map<Character, Trie> children = new HashMap<>();
    int count = 0;

    String insert(String word) {

        Trie now = this;

        StringBuilder ans = new StringBuilder();
        boolean insert = false;

        for (int i = 0, length = word.length(); i < length; i++) {
            char c = word.charAt(i);
            if (!insert) {
                ans.append(c);
            }
            if (!now.children.containsKey(c)) {
                insert = true;
            }
            now = now.children.computeIfAbsent(c, key -> new Trie());
        }

        now.count++;

        if (insert) {
            return ans.toString();
        } else {
            if (now.count > 1)
                ans.append(now.count);
            return ans.toString();
        }

    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(re.readLine());

        Trie inputData = new Trie();
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < n; i++) {
            ans.append(inputData.insert(re.readLine())).append('\n');
        }
        System.out.print(ans);
        re.close();
    }
}