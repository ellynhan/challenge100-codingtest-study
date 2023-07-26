import java.util.*;
import java.util.Map.Entry;
import java.io.*;

class Trie {
    Map<String, Trie> children = new TreeMap<>();

    void insert(String word) {
        StringTokenizer token = new StringTokenizer(word);

        Trie now = this;
        for (int i = 0, length = Integer.parseInt(token.nextToken()); i < length; i++) {
            String s = token.nextToken();
            now = now.children.computeIfAbsent(s, k -> new Trie());
        }
    }
}

public class Main {
    static String line = new String(new char[31]).replace("\0", "--");
    static StringBuilder ans = new StringBuilder();

    static void dfs(int depth, Trie now) {

        for (Entry<String, Trie> iter : now.children.entrySet()) {
            ans.append(line.subSequence(0, depth * 2)).append(iter.getKey()).append('\n');
            dfs(depth + 1, iter.getValue());
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(re.readLine());

        Trie trie = new Trie();
        for (int i = 0; i < n; i++) {
            trie.insert(re.readLine());
        }
        dfs(0, trie);
        System.out.print(ans);
        re.close();
    }
}